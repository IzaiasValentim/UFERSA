/**
 * \file model.h
 *
 * \brief Header com protótipos de funções para manipulação de modelo 3D.
 *
 * \author
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-Árido \n
 * Departamento de Engenharias e Tecnologia \n
 * petrucio at ufersa (dot) edu (dot) br
 *
 * \version 1.0
 * \date May 2025
 */

#ifndef MODEL_H
#define MODEL_H

#define WIDTH 800
#define HEIGHT 800
#define MAX_VERTICES 50000
#define MAX_FACES 50000
#define MAX_FACE_VERTS 32
#define M_PI 3.14159265358979323846

typedef struct
{
  float x, y, z;
} Vertex;

typedef struct
{
  int verts[MAX_FACE_VERTS];
  int n;
} Face;

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);

void clr();

void save();

void draw_line(int x0, int y0, int x1, int y1);

int load_obj(const char *filename, Vertex *vertices, int *vcount,
             Face *faces, int *fcount, int rotationAngle, float scaleFactor, int translate, int quadrant, char axis, int shear_value);

void resizing(Vertex v0, Vertex v1);

void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount);

Vertex get_center(Vertex *vertices, int count);

void translate_vertices(Vertex *vertices, int count, int translate);

void rotate_and_scale_vertices(Vertex *src, Vertex *dst, int count,
                               Vertex center, float angleRadians, float scaleFactor);

void reflect_model(Vertex *vertices, int numVertices, int quadrant);

void shear_model(Vertex *vertices, int numVertices, char axis, int shear_value);
#endif
