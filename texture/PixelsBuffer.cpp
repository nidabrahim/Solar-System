/******************************************************************************\
*     Copyright (C) 2017 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: PixelsBuffer.cpp                                                   * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include <cstring>
#include "PixelsBuffer.h"


PixelsBuffer::PixelsBuffer():
        mWidth(0),
        mHeight(0),
        mBytesPerPixel(0),
        mScanLineWidth(0),
        mPixels() {}

PixelsBuffer::PixelsBuffer(int width, int height, int bytesPerPixel):
        mWidth(width),
        mHeight(height),
        mBytesPerPixel(bytesPerPixel),
        mScanLineWidth(width * bytesPerPixel + (4 - (width * bytesPerPixel) % 4) % 4),
        mPixels(mScanLineWidth * height, 0xff) {}

PixelsBuffer::PixelsBuffer(int width, int height, int bytesPerPixel, unsigned char *data):
        mWidth(width),
        mHeight(height),
        mBytesPerPixel(bytesPerPixel),
        mScanLineWidth(width * bytesPerPixel + (4 - (width * bytesPerPixel) % 4) % 4),
        mPixels(mScanLineWidth * height) {
  memcpy(mPixels.data(), data, mScanLineWidth * height);
}

void PixelsBuffer::SetSize(int width, int height, int bytesPerPixel) {
  mWidth = width;
  mHeight = height;
  mBytesPerPixel = bytesPerPixel;
  mScanLineWidth = width * bytesPerPixel + (4 - (width * bytesPerPixel) % 4) % 4;
  mPixels = std::vector<unsigned char>(mScanLineWidth * height, 0xff);
}

int PixelsBuffer::GetWidth() {
  return mWidth;
}

int PixelsBuffer::GetHeight() {
  return mHeight;
}

int PixelsBuffer::GetBytesPerPixel() {
  return mBytesPerPixel;
}

void PixelsBuffer::SetPixelBytes(int x, int y, unsigned char *array) {
  int startByte = x * mScanLineWidth + y * mBytesPerPixel;
  memcpy(mPixels.data() + startByte, array, mBytesPerPixel);
}

unsigned char *PixelsBuffer::GetRawData() {
  return mPixels.data();
}