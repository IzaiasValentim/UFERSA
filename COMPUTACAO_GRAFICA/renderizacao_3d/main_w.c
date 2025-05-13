#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_VERTICES 50000
#define MAX_FACES 50000

/**
 * Execução:
 * 
 * Compilar: gcc main_w.c -o render_obj -lm
 * 
 * Executar: ./render_obj models/<nome>.obj <nome>.ppm <intValorRotacao> <1: total; 2 apenas vertices>
 */

typedef struct
{
    float x, y, z;
} Vertex;

typedef struct
{
    int indices[10];
    int count;
} Face;

Vertex vertices[MAX_VERTICES];
Face faces[MAX_FACES];
int vertexCount = 0, faceCount = 0;

unsigned char image[HEIGHT][WIDTH][3];

void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        image[y][x][0] = r;
        image[y][x][1] = g;
        image[y][x][2] = b;
    }
}

void drawLine(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0), dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        setPixel(x0, y0, 0, 0, 0);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void clearImage()
{
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            setPixel(x, y, 255, 255, 255);
}

void savePPM(const char *filename)
{
    FILE *f = fopen(filename, "wb");
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, 1, WIDTH * HEIGHT * 3, f);
    fclose(f);
}

void normalizeAndProject(float x, float y, float *px, float *py)
{
    *px = (x + 1.0f) * 0.5f * (WIDTH - 1);
    *py = (1.0f - (y + 1.0f) * 0.5f) * (HEIGHT - 1);
}

void render()
{
    for (int i = 0; i < faceCount; i++)
    {
        Face face = faces[i];
        for (int j = 0; j < face.count; j++)
        {
            int i0 = face.indices[j] - 1;
            int i1 = face.indices[(j + 1) % face.count] - 1;

            float x0, y0, x1, y1;
            normalizeAndProject(vertices[i0].x, vertices[i0].y, &x0, &y0);
            normalizeAndProject(vertices[i1].x, vertices[i1].y, &x1, &y1);

            drawLine((int)x0, (int)y0, (int)x1, (int)y1);
        }
    }
}

void renderVerticesOnly()
{
    for (int i = 0; i < vertexCount; i++)
    {
        Vertex v = vertices[i];

        // Projeção simples em perspectiva (ou ortográfica)
        float scale = 500.0f / (v.z + 5.0f); // evita divisão por zero
        int x = (int)(WIDTH / 2 + v.x * scale);
        int y = (int)(HEIGHT / 2 - v.y * scale);

        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        {
            image[y][x][0] = 0; // vermelho
            image[y][x][1] = 0; // verde
            image[y][x][2] = 0; // azul
        }
    }
}

void loadOBJ(const char *filename, float angleRadians)
{

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Erro ao abrir arquivo OBJ");
        exit(1);
    }

    char line[128];
    while (fgets(line, sizeof(line), file))
    {
        if (strncmp(line, "v ", 2) == 0)
        {
            Vertex v, rotated;
            sscanf(line + 2, "%f %f %f", &v.x, &v.y, &v.z);

            // Rotação no eixo Y
            rotated.x = v.x * cos(angleRadians) + v.z * sin(angleRadians);
            rotated.y = v.y;
            rotated.z = -v.x * sin(angleRadians) + v.z * cos(angleRadians);

            vertices[vertexCount++] = rotated;
        }
        else if (strncmp(line, "f ", 2) == 0)
        {
            Face f = {.count = 0};
            char *token = strtok(line + 2, " \n");
            while (token != NULL)
            {
                int vi;
                sscanf(token, "%d", &vi); // Ignora vt/vn
                f.indices[f.count++] = vi;
                token = strtok(NULL, " \n");
            }
            faces[faceCount++] = f;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Uso: %s modelo.obj saida.ppm angulo_em_graus modo(1 completo 2 apenas vertices)\n", argv[0]);
        return 1;
    }
    int modo = atoi(argv[4]);
    float angleDegrees = atof(argv[3]);
    float angleRadians = angleDegrees * M_PI / 180.0f;

    clearImage();
    loadOBJ(argv[1], angleRadians);

    if (modo == 1)
    {
        render();
    }
    else if (modo == 2)
    {
        renderVerticesOnly();
    }

    savePPM(argv[2]);

    printf("Imagem gerada em %s\n", argv[2]);
    return 0;
}
