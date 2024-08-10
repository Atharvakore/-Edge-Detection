#include "convolution.h"

#include <stdlib.h>

#include "image.h"

void convolve(float *result, const float *img, int w, int h,
              const float *matrix, int w_m, int h_m) {
  
    
    // TODO: Implement me!
    ///check if the given matrix is odd A good check for eval tests
    int totalrun= w_m * h_m ;
    if(totalrun %2 ==0  ){
      return;
    }
    int x=0;
    int y=0;
    int l = w*h;
    int mx = (w_m - 1)/2;
    int my = (h_m - 1)/2;
    float mij = 0.0f ;
    float res = 0.0f ;
    float p = 0.0f ;
    for (int  k= 0 ;k<l ; k++ ){
    if(x==w){
     y=y+1;
     x=0;
     }
     //Formula Part
     for(int j = 0 ; j < (h_m  );j++){
       for(int i = 0 ; i <(w_m );i++ ){
        mij = matrix[ j*w_m +i ] ;
        p = get_pixel_value( img,w, h,(x-mx+i),(y-my+j));
        res = res +  mij * p;
      
       
       }
     }
    result [y*w + x]=res;
    res = 0.0 ;
    x++;
    }
}
