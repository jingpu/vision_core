#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <stdio.h>
#include <string.h>
#include <stdexcept>
#include "qdbmp.h"
#include <xtensa/xt_reftb.h>

template <typename T>
class Image
{
public:
  T* mData;  /* HACK Just for efficient access, not secure*/

  Image(int width, int height, int channels, T padding);
  Image(T* ptr, int width, int height, int channels, T padding);
  ~Image() { if(free) delete[] mData; }

  // getter and setter
  inline T& operator()(int x, int y, int c = 0);
  inline const T& operator()(int x, int y, int c = 0) const;

  inline int width() const { return mWidth; }
  inline int height() const { return mHeight; }
  inline int channels() const { return mChannels; }

  // read and write file functions
  void load(const char* filename) { readBMP(filename); }
  void save(const char* filename) const { saveBMP(filename); }
  
  void padZeros(const Image<T> &img, int rowsTop, int rowsBottom);

  void dumpDAT(const char* var_name);
  void loadDAT(const unsigned char *data);
  void cmpDAT(const unsigned char *data);

  bool equal(const Image<T> &img) const;

private:
  int mWidth;
  int mHeight;
  int mChannels;
  T mPadding;
  bool free;

  void readBMP(const char* filename);
  void saveBMP(const char* filename) const;
};


/**
 * Creates an empty image of the specified width and height.
 */
template <typename T>
Image<T>::Image(int width, int height, int channels, T padding)
{
  printf("constructing Image object: w=%d, h=%d, c=%d, pixel size= %ub\n",
  	 width, height, channels, sizeof(T));
  mWidth = width;
  mHeight = height;
  mChannels = channels;
  mData = new T[mWidth * mHeight * mChannels];
  mPadding = padding;
  free = true;
}

template <typename T>
Image<T>::Image(T* ptr, int width, int height, int channels, T padding)
{
  mWidth = width;
  mHeight = height;
  mChannels = channels;
  mData = ptr;
  mPadding = padding;
  free = false;
}



template <typename T>
inline T& Image<T>::operator()(int x, int y, int c)
{
  if(x >= 0 && x < mWidth &&
     y >= 0 && y < mHeight &&
     c >= 0 && c < mChannels){
    // Data is stored with channels interlaced
    return(mData[y*mWidth*mChannels + x*mChannels + c]);
  } else {
    throw std::range_error("Trying to get non-const ref of pixel out of range.");
  }
}

template <typename T>
inline const T& Image<T>::operator()(int x, int y, int c) const
{
  if(x >= 0 && x < mWidth &&
     y >= 0 && y < mHeight &&
     c >= 0 && c < mChannels){
    // Data is stored with channels interlaced
    return(mData[y*mWidth*mChannels + x*mChannels + c]);
  } else {
    return mPadding;
  }
}

template <typename T>
bool Image<T>::equal(const Image<T> &img) const
{
  if (mWidth != img.width() || mHeight != img.height() 
      || mChannels != img.channels()) {
    printf("DEBUG: equal(): sizes don't match.\n");
    return false;
  }
  for(int i = 0; i < mHeight; i++)
    for(int j = 0; j < mWidth; j++)
      for(int k = 0; k < mChannels; k++)
	if (operator()(j, i, k) != img(j, i, k)) {
	  printf("DEBUG: equal(): values (%d vs %d) at [%d, %d, %d] don't match.\n",
		 operator()(j, i, k), img(j, i, k), i, j, k);
	  return false;
	}
  printf("DEBUG: equal(): two images are the same.\n");
  return true;
}


template <typename T>
void Image<T>::readBMP(const char* filename)
{
  BMP*	bmp;
  int	width, height, depth;
  UCHAR	r, g, b;
  int	x, y;

  /* Read an image file */
  bmp = BMP_ReadFile( filename );
  BMP_CHECK_ERROR( stdout, -1 );

  /* Get image's dimensions */
  width = BMP_GetWidth( bmp );
  height = BMP_GetHeight( bmp );
  depth = BMP_GetDepth( bmp );

  // TODO check dim
  printf("Successfully loaded %d x %d x %db image: %s\n", width, height, depth, filename);
  
  /* Iterate through all the image's pixels */
  for ( y = 0 ; y < height ; ++y ) {
    for ( x = 0 ; x < width ; ++x ) {
      /* Get pixel's RGB values */
      BMP_GetPixelRGB( bmp, x, y, &r, &g, &b );
      BMP_CHECK_ERROR( stdout, -1 );

      mData[y*mWidth*mChannels + x*mChannels + 0] = r;
      mData[y*mWidth*mChannels + x*mChannels + 1] = g;
      mData[y*mWidth*mChannels + x*mChannels + 2] = b;
    }
  }


  /* Free all memory allocated for the image */
  BMP_Free( bmp );
}


template <typename T>
void Image<T>::saveBMP(const char* filename) const
{

  UCHAR	r, g, b;
  int	x, y;
  BMP*	bmp;
 
  bmp = BMP_Create(mWidth, mHeight, 24);
  BMP_CHECK_ERROR( stdout, -2 );

  for ( y = 0 ; y < mHeight ; ++y ) {
    for ( x = 0 ; x < mWidth ; ++x ) {
      r = mData[y*mWidth*mChannels + x*mChannels + 0];

      if (mChannels == 3 ){
	g = mData[y*mWidth*mChannels + x*mChannels + 1];
	b = mData[y*mWidth*mChannels + x*mChannels + 2];
      } else if (mChannels == 1) {
	g = b = r;
      } else
	throw std::runtime_error("Image<T>::saveBMP(): unsupported channel number");

      BMP_SetPixelRGB( bmp, x, y, r, g, b );

      //printf("write file %s pixel[%d][%d] = (%d, %d)\n", filename, y, x, r, mData[y*mWidth*mChannels + x*mChannels + 0]);
    }
  }


  /* Save result */
  BMP_WriteFile( bmp, filename );
  BMP_CHECK_ERROR( stdout, -2 );

  /* Free all memory allocated for the image */
  BMP_Free( bmp );
}


template <typename T>
void Image<T>::dumpDAT(const char* var_name)
{
  FILE *fp;
  size_t size = mWidth * mHeight * mChannels * sizeof(T);
  unsigned char *data = (unsigned char *)mData;
  const int item_per_line = 12;
  fp= fopen("data.h","a");
  fprintf(fp, "static unsigned char\n");
  fprintf(fp, "\t%s[] = \n", var_name);
  fprintf(fp, "{");
  for (int i = 0; i < size; i++) {
    if (i % item_per_line == 0)
      fprintf(fp, "\n");
    fprintf(fp, "0x%02X, ", data[i]);
  }
  fprintf(fp, "\n};\n\n");
  fclose(fp);
}


template <typename T>
void Image<T>::loadDAT(const unsigned char *data)
{
  size_t size  = mWidth * mHeight * mChannels * sizeof(T);
  memcpy(mData, data, size);
}


template <typename T>
void Image<T>::cmpDAT(const unsigned char *data)
{
  size_t size = mWidth * mHeight * mChannels * sizeof(T);

  int res = memcmp (mData, data, size);
  if (res == 0){
    pass("Image compare pass.");
    printf("Image compare pass.\n");
  } else {
    fail("Image compare fail.");
    printf("Image compare fail.\n");
  }
}

template <typename T>
void Image<T>::padZeros(const Image<T> &fromImg, int rowsAbove, int rowsBelow)
{
  if (fromImg.height() + rowsAbove + rowsBelow != mHeight)
    throw std::runtime_error("dimentions don't match");
  
  size_t dataStart  = mWidth * mChannels * sizeof(T) * rowsAbove;
  size_t dataEnd  = mWidth * mChannels * sizeof(T) * (rowsAbove + fromImg.height());
  size_t dataSize  = mWidth * fromImg.height() * mChannels * sizeof(T);
  size_t endZeroSize  = mWidth *  mChannels * sizeof(T) * rowsBelow;

  // pad zeros
  if(dataStart)
    memset(mData, 0, dataStart);
  // copy data
  memcpy((char *)mData + dataStart, fromImg.mData, dataSize);
  // pad zeros
  if(endZeroSize)
    memset((char *)mData + dataEnd, 0, endZeroSize);
}


#endif

