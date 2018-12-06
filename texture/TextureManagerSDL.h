#ifndef HEADER_TEXTUREMANAGERSDL_H
#define HEADER_TEXTUREMANAGERSDL_H

#include <SDL2/SDL.h>
#include "PixelsBuffer.h"

class TextureManagerSDL {

	u_int32_t mTexId;
	PixelsBuffer mBuffer;
	
  public :
	TextureManagerSDL ();
	TextureManagerSDL (const  char* pathToBMP);
	~TextureManagerSDL ();
	void SelectTexture2D () const;
	void CreeBufferFormPicture (const  char* pathToBMP);
	void CreeTexture2D ();
	
  private :
	SDL_Surface*  CreeSurface (const  char* pathToBMP);
	
};

#endif
