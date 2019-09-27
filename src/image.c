#include <stdio.h>
#include <stdlib.h>


typedef struct{
    unsigned char r, g, b;
} Pixel;

typedef struct{
    unsigned int w, h;
    Pixel **pixels;
    
} Image;

void readImage(Image *img){
    int l, c;
    scanf("%u %u", &img->w, &img->h);

    //Alocação da matriz
    img->pixels = malloc(img->h * sizeof(Pixel*));
    
    for(l = 0; l < img->h;l++){
        img->pixels[l] = malloc(img->w * sizeof(Pixel));
        for(c = 0; c < img->w;c++){
            unsigned char r, g, b;
            scanf("%hhu %hhu %hhu", &r, &g, &b);
            img->pixels[l][c].r = r;
            img->pixels[l][c].g = g;
            img->pixels[l][c].b = b;
        }
    }
}

void writeImage(Image img){
    int l, c;
    
    for(l = 0; l < img.h;l++){
        for(c = 0; c < img.w;c++){
            unsigned char r, g, b;
            r = img.pixels[l][c].r;
            g = img.pixels[l][c].g;
            b = img.pixels[l][c].b;
            printf("%02hhu %02hhu %02hhu    ", r, g, b);
        }
        printf("\n");
    }
}

void grayScale(Image *img){
    int l, c;
    
    for(l = 0; l < img->h;l++){
        for(c = 0; c < img->w;c++){
            unsigned r = img->pixels[l][c].r;
            unsigned g = img->pixels[l][c].g;
            unsigned b = img->pixels[l][c].b;
            unsigned char avg = (r + g + b) /3;
            
            img->pixels[l][c].r = avg;
            img->pixels[l][c].g = avg;
            img->pixels[l][c].b = avg;
        }
    }
}

void main(){
    Image img;
    readImage(&img);
    grayScale(&img);
    writeImage(img);
}