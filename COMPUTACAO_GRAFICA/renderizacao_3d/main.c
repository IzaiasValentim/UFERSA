/**
 * \file wireframe.c
 *
 * \brief Implementação do arquivo principal de renderização do modelo 3D.
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

/**
 * Complementado por:
 * Discente: Luis Izaías Valentim de Aquino
 *
 * Compilação: gcc main.c src/model.c -o main -lm
 * Execução: ./main  <fator escala> <angulo de rotacao> <valor de tranlação> <quadrante de reflexao> <eixo_cisalhamento x ou y> <valor> > saida.ppm
 *
 */

#include <stdio.h>
#include "./include/model.h"

int main(int argc, char *argv[])
{

    if (argc < 7)
    {
        printf("Uso: %s <escala> <angulo> <translade> <quadrante> <eixo_cisalhamento> <valor> > saida.ppm\n", argv[0]);
        return 1;
    }

    Vertex vertices[MAX_VERTICES];
    Face faces[MAX_FACES];
    int vcount, fcount;

    float scaleFactor = atoi(argv[1], NULL);
    int angleDegrees = atoi(argv[2]);
    int translade = atoi(argv[3]);
    int quadrant = atoi(argv[4]);
    char shearAxis = argv[5][0];
    int shearValue = atoi(argv[6]);
    clr();

    // Lê o arquivo OBJ enviado
    if (!load_obj("models/robot.obj", vertices, &vcount, faces,
                  &fcount, angleDegrees, scaleFactor, translade, quadrant, shearAxis, shearValue))
    {
        return 1;
    }

    // Renderiza as faces no framebuffer
    render_faces(vertices, faces, vcount, fcount);

    save();

    return 0;
}
