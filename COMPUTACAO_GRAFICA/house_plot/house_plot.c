#include <stdio.h>

#define h 400
#define w 400

unsigned char img[h][w][3];

int convertY(int y) { // Converte a coordenada y para início no canto inferior esquerdo.
    return h - 1 - y;
}

void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    int newY = convertY(y);
    if (x >= 0 && x < w && newY >= 0 && newY < h) {
        img[newY][x][0] = r;
        img[newY][x][1] = g;
        img[newY][x][2] = b;
    }
}


void clearImg(){
    for(int i =0; i<h; i++){
        for(int j =0; j<w; j++){
            for(int c =0; c<3; c++){
                img[i][j][c] = 200;
            }
        }
    }
}

void saveImage(){
    printf("P3\n %d \t %d\n255\n", h, w);

    for(int i =0; i<h; i++){
        for(int j =0; j<w; j++){
            for(int c =0; c<3; c++){
                printf("%d \t", img[i][j][c]);
            }
        }
    }
    printf("\n");
}

void drawLine(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b) {
    for(float t = 0.0; t < 1; t = t +0.0001){
        int x = (int)(x0 + t * (x1 - x0));
        int y = (int)(y0 + t * (y1 - y0));
        setPixel(x, y, r, g, b);
    }
}

int main() {
    clearImg();
   
    // Linha do chão da casa:
    drawLine(100, 100, 300, 100, 255, 255, 0); 
    // Linha da parede esquerda da casa:
    drawLine(300, 100, 300, 200, 255, 255, 0); 
    // Linha da parede direita da casa:
    drawLine(100, 100, 100, 200, 255, 255, 0);
    // Linha da base do telhado da casa:
    drawLine(90, 200, 310, 200, 255, 255, 0);
    // Linha da esquerda do telhado da casa:
    drawLine(90, 200, 200, 300, 255, 255, 0);
    // Linha da direita do telhado da casa:
    drawLine(310, 200, 200, 300, 255, 255, 0);

    // Linha da porta da casa:
    drawLine(150, 100, 150, 150, 255, 255, 0);
    // Linha da esquerda da porta da casa:
    drawLine(150, 150, 200, 150, 255, 255, 0);
    // Linha da direita da porta da casa:
    drawLine(200, 150, 200, 100, 255, 255, 0);
    saveImage(); // Save the image to a PPM file
    return 0;
}

