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

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    image[y][x][0] = r;
    image[y][x][1] = g;
    image[y][x][2] = b;
  }
}

void draw_line(int x0, int y0, int x1, int y1) {
  float t;
  for (t = 0.0; t < 1.0; t = t + 0.0001)
    set_pixel((int)x0 + (x1 - x0) * t, (int)y0 + (y1 - y0) * t, 0, 0, 0);
}

void clr() {
  int i, j, c;
  for (i = 0; i < WIDTH; i++)
    for (j = 0; j < HEIGHT; j++)
      for (c = 0; c < 3; c++)
        image[i][j][c] = 255;
}

void save() {
  int i, j, c;
  printf("P3\n %d \t %d\n 255\n", WIDTH, HEIGHT);
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      for (c = 0; c < 3; c++) {
        printf("%d \t", image[i][j][c]);
      }
      printf("\n");
    }
  }
}

int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces, int *fcount) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Erro ao abrir o arquivo");
    return 0;
  }

  char line[512];
  *vcount = 0;
  *fcount = 0;

  while (fgets(line, sizeof(line), file)) {
    if (strncmp(line, "v ", 2) == 0) {
      if (sscanf(line + 2, "%f %f %f", &vertices[*vcount].x,
                 &vertices[*vcount].y, &vertices[*vcount].z) == 3) {
        (*vcount)++;
      }
    } else if (strncmp(line, "f ", 2) == 0) {
      Face face = {.n = 0};
      char *token = strtok(line + 2, " \n");
      while (token && face.n < MAX_FACE_VERTS) {
        int index;
        if (sscanf(token, "%d", &index) == 1) {
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

void resizing(Vertex v0, Vertex v1) {
  int x0 = (int)((v0.x + 1.0f) * WIDTH / 2.0f);
  int y0 = (int)((1.0f - v0.y) * HEIGHT / 2.0f);
  int x1 = (int)((v1.x + 1.0f) * WIDTH / 2.0f);
  int y1 = (int)((1.0f - v1.y) * HEIGHT / 2.0f);

  draw_line(x0, y0, x1, y1);
}

void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount) {
  int i, j;
  for (i = 0; i < fcount; i++) {
    Face face = faces[i];
    for (j = 0; j < face.n; j++) {
      Vertex v0 = vertices[face.verts[j] - 1];
      Vertex v1 = vertices[face.verts[(j + 1) % face.n] - 1];
      resizing(v0, v1);
    }
  }
}
