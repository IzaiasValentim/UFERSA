#include <stdio.h>
#include <math.h>

/**
 * Exercício 2 - Criar uma imagem PPM de uma casa com telhado triangular e porta retangular,
 * utilizando coordenadas cartesianas.
 *
 * É possível rotacionar a casa em torno de um ponto central e aplicar um fator de ampliação.
 *
 * Dimensão da imagem: 400x400 pixels.
 * Formato da imagem: PPM (Portable Pixmap Format).
 *
 * Execução:
 *  Gerar executável:
 *      > gcc ./house_plot.c -o main.exe
 *      >./main.exe > casa.ppm
 */

#define h 400
#define w 400

unsigned char img[h][w][3];

#define PI 3.14159265358979323846

float degParaRad(float degrees)
{
    return degrees * PI / 180.0;
}

int corrigeY(int y)
{
    return h - 1 - y;
}

int escalarCoordenadas(int coord, float scale)
{
    return (int)(coord * scale);
}

void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    int newY = corrigeY(y);

    if (x >= 0 && x < w && newY >= 0 && newY < h)
    {
        img[newY][x][0] = r;
        img[newY][x][1] = g;
        img[newY][x][2] = b;
    }
}

void limparTela()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int c = 0; c < 3; c++)
            {
                img[i][j][c] = 200;
            }
        }
    }
}

void salvarImagem()
{
    printf("P3\n %d \t %d\n255\n", h, w);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int c = 0; c < 3; c++)
            {
                printf("%d \t", img[i][j][c]);
            }
        }
    }
    printf("\n");
}

void plotarLinha(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b)
{
    for (float t = 0.0; t < 1; t = t + 0.0001)
    {
        int x = (int)(x0 + t * (x1 - x0));
        int y = (int)(y0 + t * (y1 - y0));
        setPixel(x, y, r, g, b);
    }
}

void rotacionarPonto(int x, int y, int cx, int cy, float angRad, int *xr, int *yr)
{
    float s = sin(angRad);
    float c = cos(angRad);

    // Translada para a origem
    float tx = x - cx;
    float ty = y - cy;

    // Aplica suas equações
    float xRotated = tx * c - ty * s;
    float yRotated = ty * c + tx * s;

    // Translada de volta
    *xr = (int)(xRotated + cx);
    *yr = (int)(yRotated + cy);
}

void transladarPonto(int x, int y, int dx, int dy, int *xt, int *yt)
{
    *xt = x + dx;
    *yt = y + dy;
}

void refletirPonto(int x, int y, char eixo, int *xr, int *yr)
{
    switch (eixo)
    {
    case 'x': // Reflexão em relação ao eixo X
        *xr = x;
        *yr = -y;
        break;
    case 'y': // Reflexão em relação ao eixo Y
        *xr = -x;
        *yr = y;
        break;
    case 'o': // Reflexão na origem (0,0)
        *xr = -x;
        *yr = -y;
        break;
    default:
        *xr = x;
        *yr = y;
    }
}

void cisalharPonto(int x, int y, float shx, float shy, int *xs, int *ys)
{
    *xs = x + (int)(shx * y);
    *ys = y + (int)(shy * x);
}

int main()
{
    limparTela();

    float fatorDeEscala = 1.0; // Fator de escala (ex: 1.5 aumenta 50%)
    float rotacaoGraus = 30.0; // Ângulo em graus
    float anguloRad = degParaRad(rotacaoGraus);

    int centerX = escalarCoordenadas(200, fatorDeEscala);
    int centerY = escalarCoordenadas(200, fatorDeEscala);

    int linhas[][4] = {
        {100, 100, 300, 100}, // Chão
        {300, 100, 300, 200}, // Parede direita
        {100, 100, 100, 200}, // Parede esquerda
        {90, 200, 310, 200},  // Base do telhado
        {90, 200, 200, 300},  // Lado esquerdo do telhado
        {310, 200, 200, 300}, // Lado direito do telhado
        {150, 100, 150, 150}, // Porta - lateral esquerda
        {150, 150, 200, 150}, // Porta - topo
        {200, 150, 200, 100}  // Porta - lateral direita
    };

    int nLinhas = sizeof(linhas) / sizeof(linhas[0]);

    for (int i = 0; i < nLinhas; i++)
    {
        // Aqui é possível aplicar a alteração de escala.
        int x0 = escalarCoordenadas(linhas[i][0], fatorDeEscala);
        int y0 = escalarCoordenadas(linhas[i][1], fatorDeEscala);
        int x1 = escalarCoordenadas(linhas[i][2], fatorDeEscala);
        int y1 = escalarCoordenadas(linhas[i][3], fatorDeEscala);

        int rx0, ry0, rx1, ry1;
        
        cisalharPonto(x0, y0,0.1,0.0, &rx0, &ry0);
        cisalharPonto(x1, y1,0.1,0.0, &rx1, &ry1);
        
        // rotacionarPonto(x0, y0, centerX, centerY, anguloRad, &rx0, &ry0);
        // rotacionarPonto(x1, y1, centerX, centerY, anguloRad, &rx1, &ry1);
        
        //transladarPonto(x0, y0, 10, 30, &rx0, &ry0);
        //transladarPonto(x1, y1, 10, 30, &rx1, &ry1);

        //refletirPonto(x0, y0, 'y', &rx0, &ry0);
        //refletirPonto(x1, y1, 'x', &rx1, &ry1);
        
        // Plot padrão:
        // plotarLinha(x0, y0, x1, y1, 255, 0, 0);

        plotarLinha(rx0, ry0, rx1, ry1, 255, 255, 0);
    }

    salvarImagem();
    return 0;
}
