
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "argparser.h"
#include "convolution.h"
#include "derivation.h"
#include "gaussian_kernel.h"
#include "image.h"
int main(int const argc, char **const argv) {
    /**
     * Parse arguments. The parsed image file name and threshold are available
     * in the image_file_name and threshold global variables (see argparser.h).
     */
    //CCCC
    parse_arguments(argc, argv);
    printf("Computing edges for image file %s with threshold %i\n",
          image_file_name, threshold);
          
    /**
     * Read Image from given file.
     *
     * If the input file is broken terminate with return value 1.
     *
     * Hint: The width and height of the image have to be accessible in the
     * scope of this function.
     */
    // TODO: Implement me!
   // int threshold = 100;
    int w ;
    int h;
    float *rf = read_image_from_file (image_file_name , &w , &h  ) ;

    if(rf==NULL){
    return 1;
 }
    /**
     * Blur the image by using convolve with the given Gaussian kernel matrix
     * gaussian_k (defined in gaussian_kernel.h). The width of the matrix is
     * gaussian_w, the height is gaussian_h.
     *
     * Afterwards, write the resulting blurred image to the file out_blur.pgm.
     */
    // TODO: Implement me!
    float *resultt = array_init( w *  h)  ;
    //if (resultt == NULL)
    //{
      // array_destroy(rf);
       //return 1;
   // }
    convolve(resultt , rf,  w , h, gaussian_k, gaussian_w, gaussian_h);
    write_image_to_file(resultt ,  w,  h, "out_blur.pgm" ) ;
    /**
     * Compute the derivation of the blurred image computed above in both x and
     * y direction.
     *
     * Afterwards, rescale both results and write them to the files out_d_x.pgm
     * and out_d_y.pgm respectively.
     */
    // TODO: Implement me!
   float *derx = array_init(w * h);
   float *dery = array_init( w *  h);
   derivation_x_direction(derx, resultt ,  w,  h);
   derivation_y_direction(dery, resultt ,  w,  h);
   float *scx = array_init(w * h);
   float *scy = array_init( w *  h);
   scale_image(scx, derx , w, h);
   scale_image(scy, dery , w, h);
   write_image_to_file(scx, w,  h, "out_d_x.pgm");
   write_image_to_file(scy, w,  h, "out_d_y.pgm");

    /**
     * Compute the gradient magnitude of the blurred image by using the
     * (unscaled!) derivations in x- and y-direction computed earlier.
     *
     * Afterwards, rescale the result and write it to out_gm.pgm.
     */
    // TODO: Implement me!
    float *gm_res = array_init(w * h);
    float *sc_res = array_init(w *  h); 
    gradient_magnitude(gm_res , derx, dery, w, h) ;
    scale_image(sc_res, gm_res , w, h);
    write_image_to_file(sc_res, w,  h, "out_gm.pgm");
    /**
     * Apply the threshold to the gradient magnitude.
     * Then write the result to the file out_edges.pgm.
     */
    // TODO: Implement me!
    apply_threshold(gm_res, w, h, threshold);
    write_image_to_file(gm_res, w,  h, "out_edges.pgm");
    /**
     * Remember to free dynamically allocated memory when it is no longer used!
     */
 array_destroy(rf);
 array_destroy(resultt);
 array_destroy(derx);
 array_destroy(dery);
 array_destroy(scx);
 array_destroy(scy);
 array_destroy(gm_res);
 array_destroy(sc_res);
}

