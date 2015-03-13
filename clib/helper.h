#ifndef _HELPER_H_
#define _HELPER_H_

#include "image.h"
#include <xtensa/tie/vision_n4m1r32t1.h>

void shuffle_s2v(const Image<int> &in, Image<vector32> &out) {
  const int w = in.width();
  const int h = in.height();
  const int c = in.channels();
  const int N = 4;  // width of SIMD

  if(w != out.width()*N || h != out.height() || c != out.channels())
    throw std::runtime_error("shuffle_s2v(): two image sizes don't match.");

  int *shuffled_img = new int[w*h*c];
  // shuffle the image
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w/N; j++)
      for(int k = 0; k < c; k++)
	for(int n = 0; n < N; n++)
	  shuffled_img[i*w*c + j*c*N + k*N + n]
	    = in(j + n*(w/N), i, k);

  // copy the shuffled image to the vector32 array
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w/N; j++)
      for(int k = 0; k < c; k++) {
	vector32 *p_v32 = (vector32 *) &shuffled_img[i*w*c + j*c*N + k*N];
	out(j, i, k) = *p_v32;
      }

  delete[] shuffled_img;
}

void shuffle_v2s(const Image<vector32> &in, Image<int> &out) {
  const int w = out.width();
  const int h = out.height();
  const int c = out.channels();
  const int N = 4;  // width of SIMD

  if(w != in.width()*N || h != in.height() || c != in.channels())
    throw std::runtime_error("shuffle_v2s(): two image sizes don't match.");

  int *shuffled_img = new int[w*h*c];

  // copy the input image to INT array
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w/N; j++)
      for(int k = 0; k < c; k++) {
	vector32 *p_v32 = (vector32 *) &shuffled_img[i*w*c + j*c*N + k*N];
	*p_v32 = in(j, i, k);
      }

  // shuffle the image, and store in the output image
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w/N; j++)
      for(int k = 0; k < c; k++)
	for(int n = 0; n < N; n++)
	  out(j + n*(w/N), i, k) = shuffled_img[i*w*c + j*c*N + k*N + n];

  delete[] shuffled_img;
}


#endif
