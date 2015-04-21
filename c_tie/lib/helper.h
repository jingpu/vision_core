#ifndef _HELPER_H_
#define _HELPER_H_

#include <stdio.h>
#include <string.h>
#include "image.h"
#include "arch.h"


template <typename V, typename S>
void shuffle_s2v(const Image<S> &in, Image<V> &out) {
  const int w = in.width();
  const int h = in.height();
  const int c = in.channels();

  if(w != out.width()*N || h != out.height() || c != out.channels())
    throw std::runtime_error("shuffle_s2v(): two image sizes don't match.");

  const size_t lane_width = sizeof(V)/N;
  char *shuffled_img = new char[w*h*c*lane_width];
  // shuffle the image
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w/N; j++)
      for(int k = 0; k < c; k++)
	for(int n = 0; n < N; n++) {
	  S in_val = in(j + n*(w/N), i, k);
	  memcpy(&shuffled_img[(i*w*c + j*c*N + k*N + n)*lane_width], &in_val, lane_width);
	}

  // copy the shuffled image to the vector32 array
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w/N; j++)
      for(int k = 0; k < c; k++) {
	vector32 *p_v32 = (vector32 *) &shuffled_img[(i*w*c + j*c*N + k*N)*lane_width];
	out(j, i, k) = *p_v32;
      }

  delete[] shuffled_img;
}

template <typename V, typename S>
void shuffle_v2s(const Image<V> &in, Image<S> &out) {
  const int w = out.width();
  const int h = out.height();
  const int c = out.channels();

  if(w != in.width()*N || h != in.height() || c != in.channels())
    throw std::runtime_error("shuffle_v2s(): two image sizes don't match.");

  const size_t lane_width = sizeof(V)/N;
  char *shuffled_img = new char[w*h*c*lane_width];

  // copy the input image to INT array
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w/N; j++)
      for(int k = 0; k < c; k++) {
	vector32 *p_v32 = (vector32 *) &shuffled_img[(i*w*c + j*c*N + k*N)*lane_width];
	*p_v32 = in(j, i, k);
      }

  // shuffle the image, and store in the output image
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w/N; j++)
      for(int k = 0; k < c; k++)
	for(int n = 0; n < N; n++) {
	  S out_val = 0;
	  memcpy(&out_val, &shuffled_img[(i*w*c + j*c*N + k*N + n)*lane_width], lane_width);
	  out(j + n*(w/N), i, k) = out_val;
	}
	  

  delete[] shuffled_img;
}


#endif
