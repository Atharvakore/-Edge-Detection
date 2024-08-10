#include "image.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void apply_threshold(float *img, int w, int h, int T) {
  if (img == NULL || w <= 0 || h <= 0) {
        printf("POBLEM\n");
    }   

    // TODO: Implement me!
    // Pixels in 1D Array

    int l = w*h;
    for (int i=0;i<l;i++)
    {
        if (img[i]>T)
        img[i]=255.0;
        else 
        img[i]=0.0;
    }
}


void scale_image(float *result, const float *img, int w, int h) {
  // TODO: Implement me!
    float min = img [0] ;
    float max = img [0] ;
    int l = w*h;
// for max of Array
     for (int i=0;i<l;i++)
    {
      
    if (img [i] > max  ){
     max = img [i];
     }
   }
// for min of Array
    for(int j = 0 ; j<l ; j++){
        
        if (img [j] < min){
        min = img [j]; 
        }
    }
// for Final result
    
        if (max == min){
          for (int k = 0 ; k<l ; k++){
         result [k] = 0.0f ;
          }
        }
        else {
          for (int k = 0 ; k<l ; k++){
            result [k] = ((img [k] - min ) * 255.f )/ (max-min);
          }
        }
    

}

  
float get_pixel_value(const float *img, int w, int h, int x, int y) {
  

    // TODO: Implement me!
    if(w<=0||h<=0||img==NULL){  ///make it make aske in forum
      return 0.0f;                
    }

    int xx ,  yy;
    float z;
    if (x<0){
      xx = abs(x) - 1 ;
    }
    if (x>=w){
      xx = 2 * w - x - 1 ; 
    }
     if (y<0){
    yy =   abs(y) - 1 ;
    }
    if (y>=h){
      yy = 2*h - y - 1 ;    
    }
    
  if (x>=0 && x<w ){
   xx = x ; 
  }
   if (y>=0 && y<h ){
   yy = y ; 
  }

z = img [yy*w + xx] ;
    return z  ;
}

float *array_init(int size) {
     float *array = (float *) malloc (size * sizeof (float)) ; 
    return array;
}



void array_destroy(float *m) {
  // (void)m;
    free (m);
  
    
    m=NULL;
}

float *read_image_from_file(const char *filename, int *w, int *h) {
    FILE *ptr = fopen(filename, "r");

    
    if (ptr == NULL) {
        return NULL;
    }

    // Header Data check

    // Empty File check
    char c = fgetc(ptr);
    if (c == EOF) {
        fclose(ptr);
        return NULL;
    }

    // FIle Format "P2" Check
    char cc = fgetc(ptr);
    if (c != 'P' || cc != '2') {
        fclose(ptr);
        return NULL;
    }

    // FILE HEIGHT , WIDTH , PIXEL CHECK
    int pix;
    if (fscanf(ptr, "%d %d", w, h) != 2) {
        fclose(ptr);
        return NULL;
    }

    if ((*h) <= 0 || (*w) <= 0) {
        fclose(ptr);
        return NULL;
    }

    if (fscanf(ptr, "%d", &pix) != 1 || pix != 255) {
        fclose(ptr);
        return NULL;
    }

    // Array Storing
    int totalpix = (*h) * (*w);
    float *arr = array_init(totalpix);
    if (arr == NULL) {
        fclose(ptr);
        return NULL;
    }

    int i = 0;
    while (i < totalpix && fscanf(ptr, "%d", &pix) == 1) {
        if (pix > 255 || pix < 0) {
            fclose(ptr);
            array_destroy(arr);
            return NULL;
        }
        arr[i] = pix;
        i++;
    }


    /////
    int temp;
    while(fscanf(ptr,"%d",&temp)==1){
    i++;
    }
   // printf("%d\n",i);
    // check total pix
    if (i != totalpix) {
        fclose(ptr);
        array_destroy(arr);
        return NULL;
    }

    
    ////
     fclose(ptr);
    return arr;
}

void write_image_to_file(const float *img, int w, int h, const char *filename) {
    
 // TODO: Implement me!
 int maxpix = 255 ;
  FILE* ptrr;
    ptrr = fopen(filename , "w");
    //if (ptrr == NULL) {
       // printf("File doesnt exist");
        //fclose(ptrr);
        //exit(1);
   // }
    fputs("P2", ptrr);
    fputs(" ", ptrr);
    fputs("\n", ptrr);
    fprintf(ptrr, "%d", w);
    fputs(" ", ptrr);
    fprintf(ptrr, "%d", h);
    fputs(" ", ptrr);
    fputs("\n", ptrr);
    fprintf(ptrr, "%d", maxpix);
    fputs("\n", ptrr);
   
   for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int pix = (int)floor(img[i * w + j]);
            fprintf(ptrr, "%d ", pix);
        }
        fprintf(ptrr, "\n");
    }

    fclose(ptrr);
    

}



