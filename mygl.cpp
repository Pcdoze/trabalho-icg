#include "definitions.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
    //*************************************************************************
    // Chame aqui as funções do mygl.h
    //*************************************************************************

    DrawLine(0, 0, 
             IMAGE_WIDTH, IMAGE_HEIGHT);
    DrawLine(0.25*IMAGE_WIDTH, 0, 
             0.75*IMAGE_WIDTH, IMAGE_HEIGHT);
    DrawLine(0.5*IMAGE_WIDTH, 0, 
             0.5*IMAGE_WIDTH, IMAGE_HEIGHT);
    DrawLine(0.75*IMAGE_WIDTH, 0, 
             0.25*IMAGE_WIDTH, IMAGE_HEIGHT);

    DrawLine(IMAGE_WIDTH, 0, 
             0, IMAGE_HEIGHT);
    DrawLine(IMAGE_WIDTH, 0.25*IMAGE_HEIGHT, 
             0, 0.75*IMAGE_HEIGHT);
    DrawLine(IMAGE_WIDTH, 0.5*IMAGE_HEIGHT, 
             0, 0.5*IMAGE_HEIGHT);         
    DrawLine(IMAGE_WIDTH, 0.75*IMAGE_HEIGHT, 
             0, 0.25*IMAGE_HEIGHT);
}

void PutPixel(int x, int y) {
    FBptr[4 * x + 4 * y * IMAGE_WIDTH + 0] = 255;
    FBptr[4 * x + 4 * y * IMAGE_WIDTH + 1] = 255;
    FBptr[4 * x + 4 * y * IMAGE_WIDTH + 2] = 255;
    FBptr[4 * x + 4 * y * IMAGE_WIDTH + 3] = 255;
}

void DrawLine(int x1, int y1, int x2, int y2)
{
    int c = 0;
    int cf = 0;

    double ix = 0.0;
    double iy = 0.0;

    int diff_x = x2-x1;
    int diff_y = y2-y1;

    int adiff_x = abs(diff_x);
    int adiff_y = abs(diff_y);


    if(adiff_x > adiff_y){
        ix = diff_x > 0 ? 1 : -1;
        iy = (diff_x != 0) ? abs((double)(diff_y)/(double)(diff_x)) : 0;

        if(diff_y < 0){ iy *= -1; }

        c = 0;
        cf = adiff_x;
    }
    else if(adiff_x < adiff_y){
        iy = diff_y > 0 ? 1 : -1;
        ix = (diff_y != 0) ? abs((double)(diff_x)/(double)(diff_y)) : 0;
        
        if(diff_x < 0){ ix *= -1; }

        c = 0;
        cf = adiff_y;
    }
    else{
        iy = diff_y > 0 ? 1 : -1;
        ix = diff_x > 0 ? 1 : -1;
        
        c = 0;
        cf = abs(diff_y);
    }

    double cx = x1;
    double cy = y1;

    while (c < cf){
        PutPixel(floor(cx), floor(cy));
        //PutPixel(ceil(cx), ceil(cy));

        cx += ix;
        cy += iy;
        c++;
    }
}

void DrawTriangle(
    int x1, int y1, 
    int x2, int y2, 
    int x3, int y3)
{
    DrawLine(x1, y1, x2, y2);
    DrawLine(x2, y2, x3, y3);
    DrawLine(x3, y3, x1, y1);
}


// void DrawLine(void)
// {
//     for (unsigned int i = 0; i < 250; ++i)
//     {
//         FBptr[4 * i + 4 * i * IMAGE_WIDTH + 0] = 255;
//         FBptr[4 * i + 4 * i * IMAGE_WIDTH + 1] = 255;
//         FBptr[4 * i + 4 * i * IMAGE_WIDTH + 2] = 255;
//         FBptr[4 * i + 4 * i * IMAGE_WIDTH + 3] = 255;
//     }
// }
//
// void PutPixel(void) {
//     // Escreve um pixel vermelho na posicao (0,0) da tela:
//     FBptr[0] = 255; // componente R
//     FBptr[1] = 0;   // componente G
//     FBptr[2] = 0;   // componente B
//     FBptr[3] = 255; // componente A

//     // Escreve um pixel verde na posicao (1,0) da tela:
//     FBptr[4] = 0;   // componente R
//     FBptr[5] = 255; // componente G
//     FBptr[6] = 0;   // componente B
//     FBptr[7] = 255; // componente A

//     // Escreve um pixel azul na posicao (2,0) da tela:
//     FBptr[8] = 0;    // componente R
//     FBptr[9] = 0;    // componente G
//     FBptr[10] = 255; // componente B
//     FBptr[11] = 255; // componente A
// }