/**
 * \file model.c
 *
 * \brief Implementa��o das fun��es de manipula��o do modelo 3D.
 *
 * \author
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-�rido \n
 * Departamento de Engenharias e Tecnologia \n
 * petrucio at ufersa (dot) edu (dot) br
 *
 * \version 1.0
 * \date May 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../include/model.h"

unsigned char image[HEIGHT][WIDTH][3];

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
  {
    image[y][x][0] = r;
    image[y][x][1] = g;
    image[y][x][2] = b;
  }
}

void draw_line(int x0, int y0, int x1, int y1)
{
  float t;
  for (t = 0.0; t < 1.0; t = t + 0.0001)
    set_pixel((int)x0 + (x1 - x0) * t, (int)y0 + (y1 - y0) * t, 0, 0, 0);
}

void clr()
{
  int i, j, c;
  for (i = 0; i < WIDTH; i++)
    for (j = 0; j < HEIGHT; j++)
      for (c = 0; c < 3; c++)
        image[i][j][c] = 255;
}

void save()
{
  int i, j, c;
  printf("P3\n %d \t %d\n 255\n", WIDTH, HEIGHT);
  for (i = 0; i < WIDTH; i++)
  {
    for (j = 0; j < HEIGHT; j++)
    {
      for (c = 0; c < 3; c++)
      {
        printf("%d \t", image[i][j][c]);
      }
      printf("\n");
    }
  }
}

Vertex get_center(Vertex *vertices, int count)
{
  Vertex center = {0, 0, 0};
  for (int i = 0; i < count; i++)
  {
    center.x += vertices[i].x;
    center.y += vertices[i].y;
    center.z += vertices[i].z;
  }
  center.x /= count;
  center.y /= count;
  center.z /= count;
  return center;
}

void rotate_and_scale_vertices(Vertex *src, Vertex *dst, int count, Vertex center, float angleRadians, float scaleFactor)
{
  for (int i = 0; i < count; i++)
  {
    Vertex v = src[i];
    Vertex t;

    // Translada para origem
    v.x -= center.x;
    v.y -= center.y;
    v.z -= center.z;

    // Roda em Y
    t.x = v.x * cos(angleRadians) + v.z * sin(angleRadians);
    t.y = v.y;
    t.z = -v.x * sin(angleRadians) + v.z * cos(angleRadians);

    // Aplica escala
    t.x *= scaleFactor;
    t.y *= scaleFactor;
    t.z *= scaleFactor;

    // Translada de volta
    t.x += center.x;
    t.y += center.y;
    t.z += center.z;

    dst[i] = t;
  }
}

void translate_vertices(Vertex *vertices, int count, int translate)
{
  int i;
  for (i = 0; i < count; i++)
  {
    vertices[i].x += vertices[i].x * (float)translate / 100;
    vertices[i].y += vertices[i].y * (float)translate / 100;
    vertices[i].z += vertices[i].z * (float)translate / 100;
  }
}

void reflect_model(Vertex *vertices, int numVertices, int quadrant)
{
  for (int i = 0; i < numVertices; i++)
  {
    switch (quadrant)
    {
    case 1:
      break;
    case 2:
      vertices[i].x *= -1;
      break;
    case 3:
      vertices[i].x *= -1;
      vertices[i].y *= -1;
    case 4:
      vertices[i].y *= -1;
      break;
    default:
      return;
    }
  }
}

void shear_model(Vertex *vertices, int numVertices, char axis, int shear_value)
{
  for (int i = 0; i < numVertices; i++)
  {
    if (axis == 'x' || axis == 'X')
    {
      vertices[i].x += shear_value * vertices[i].y;
    }
    else if (axis == 'y' || axis == 'Y')
    {
      vertices[i].y += shear_value * vertices[i].x;
    }
  }
}

int load_obj(const char *filename, Vertex *vertices, int *vcount,
             Face *faces, int *fcount, int rotationAngle, float scaleFactor, int translate, int quadrant, char axis, int shear_value)
{
  FILE *file = fopen(filename, "r");
  if (!file)
  {
    perror("Erro ao abrir o arquivo");
    return 0;
  }

  // Não aceita escala nula.
  if (scaleFactor == 0.0f)
  {
    scaleFactor = 1.0f;
    // Se o fator de escala ser negativo, o objeto será reduzido.
  }
  else if (scaleFactor < 0.0f)
  {
    scaleFactor = -1.0f / scaleFactor;
  }

  char line[512];
  Vertex temp_vertices[MAX_VERTICES];
  int temp_vcount = 0;

  *vcount = 0;
  *fcount = 0;

  // Lê todos os vértices primeiro (sem rotacionar)
  while (fgets(line, sizeof(line), file))
  {
    if (strncmp(line, "v ", 2) == 0)
    {
      Vertex v;
      if (sscanf(line + 2, "%f %f %f", &v.x, &v.y, &v.z) == 3)
      {
        temp_vertices[temp_vcount++] = v;
      }
    }
  }

  // Calcula centro do modelo
  Vertex center = get_center(temp_vertices, temp_vcount);

  // Aplica rotação corrigida ao redor do centro
  float angleRadians = rotationAngle * M_PI / 180.0f;

  rotate_and_scale_vertices(temp_vertices, vertices, temp_vcount, center, angleRadians, scaleFactor);

  *vcount = temp_vcount;

  if (translate != 0)
  {
    translate_vertices(vertices, temp_vcount, translate);
  }

  if (quadrant > 0 && quadrant < 5)
  {
    // Aplica o espelhamento no modelo
    reflect_model(vertices, *vcount, quadrant);
  }

  if ((axis == 'x' || axis == 'X' || axis == 'y' || axis == 'Y') && shear_value != 0.0f)
  {
    // Aplica o cisalhamento no modelo
    shear_model(vertices, *vcount, axis, shear_value);
  }

  // Volta ao início para ler as faces
  rewind(file);
  while (fgets(line, sizeof(line), file))
  {
    if (strncmp(line, "f ", 2) == 0)
    {
      Face face = {.n = 0};
      char *token = strtok(line + 2, " \n");
      while (token && face.n < MAX_FACE_VERTS)
      {
        int index;
        if (sscanf(token, "%d", &index) == 1)
        {
          face.verts[face.n++] = index;
        }
        token = strtok(NULL, " \n");
      }
      faces[(*fcount)++] = face;
    }
  }

  fclose(file);
  return 1;
}

void resizing(Vertex v0, Vertex v1)
{
  int x0 = (int)((v0.x + 1.0f) * WIDTH / 2.0f);
  int y0 = (int)((1.0f - v0.y) * HEIGHT / 2.0f);
  int x1 = (int)((v1.x + 1.0f) * WIDTH / 2.0f);
  int y1 = (int)((1.0f - v1.y) * HEIGHT / 2.0f);

  draw_line(x0, y0, x1, y1);
}

void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount)
{
  int i, j;
  for (i = 0; i < fcount; i++)
  {
    Face face = faces[i];
    for (j = 0; j < face.n; j++)
    {
      Vertex v0 = vertices[face.verts[j] - 1];
      Vertex v1 = vertices[face.verts[(j + 1) % face.n] - 1];
      resizing(v0, v1);
    }
  }
}
