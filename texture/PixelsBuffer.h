/******************************************************************************\
*     Copyright (C) 2017 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: PixelsBuffer.h                                                     * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#ifndef HEADER_PIXELBUFFER_H
#define HEADER_PIXELBUFFER_H

#include <vector>

class PixelsBuffer {
  int mWidth; // largeur (pixels)
  int mHeight; // hauteur (pixels)
  int mBytesPerPixel; // Nombre d'octets par pixel
  int mScanLineWidth; // Largeur d'une scanline doit être multiple de 4
                      // = width*bytesPerPixel + ((4-(width*bytesPerPixel)%4)%4);
  std::vector<unsigned char> mPixels; // couleurs des pixels dans un tableau contigu.

  /** Constructeur par défaut */
  PixelsBuffer();

public:

  /** Constructeur avec fond blanc */
  PixelsBuffer(int width, int height, int bytesPerPixel);

  /** Constructeur en copiant un buffer */
  PixelsBuffer(int width, int height, int bytesPerPixel, unsigned char* data);

  /** Modifie la taille du buffer
   * @return true si la dimension du buffer suffit
   **/
  void SetSize(int width, int height, int bytesPerPixel);

  /** Width accessor */
  int GetWidth();

  /** Height accessor */
  int GetHeight();

  /** Bytes Per Pixel accessor */
  int GetBytesPerPixel();

  /** Set pixelsvalues */
  void SetPixelBytes(int x, int y, unsigned char *array);

  /** Acces raw pointer to pixels */
  unsigned char* GetRawData();
};
#endif //HEADER_PIXELBUFFER_H
