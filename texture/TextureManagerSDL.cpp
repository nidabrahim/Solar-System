#include<GLES3/gl3.h>
#include<GL/glut.h>
#include "TextureManagerSDL.h"


TextureManagerSDL::TextureManagerSDL():mTexId(0),mBuffer(0,0,0)
{}

TextureManagerSDL::TextureManagerSDL(const  char* pathToBMP)
:mTexId (0),mBuffer (0,0,0)
{
	CreeBufferFormPicture (pathToBMP) ;
	CreeTexture2D();
}

TextureManagerSDL::~TextureManagerSDL(){
	glDeleteTextures(1,&mTexId);
}

void TextureManagerSDL::SelectTexture2D() const
{
    fprintf(stderr,"Debut SelectTexture2D\n");
	glBindTexture (GL_TEXTURE_2D,mTexId);
    fprintf(stderr,"Fin SelectTexture2D\n");
}

void TextureManagerSDL::CreeBufferFormPicture( const  char* pathToBMP){
    // Chargement de l’Image au format BMP
	SDL_Surface* surface = CreeSurface (pathToBMP);
    // Création d’un buffer maison à partir de la surface SDL
	mBuffer = PixelsBuffer(surface->w,surface->h,surface->format->BytesPerPixel,(uint8_t*) surface->pixels);
    // Libération de la surface
	SDL_FreeSurface(surface);
}

void TextureManagerSDL::CreeTexture2D(){
	glDeleteTextures(1,&mTexId);
	glGenTextures(1,&mTexId);
	SelectTexture2D();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	GLint mode ;

	switch (mBuffer.GetBytesPerPixel()) {
	case 1: mode = GL_LUMINANCE; break;
	case 2: mode = GL_RGB; break;
	case 3: mode = GL_RGBA; break;
	default:
		fprintf(stderr,"Nombre de bits par pixels non géré\n");
		return;
	}
	
	glTexImage2D (GL_TEXTURE_2D,0,mode,mBuffer.GetWidth(),mBuffer.GetHeight(),0,mode,GL_UNSIGNED_BYTE,mBuffer.GetRawData());
     fprintf(stderr,"nn : %d \n",mTexId);
	glBindTexture (GL_TEXTURE_2D,mTexId);
   
}

SDL_Surface* TextureManagerSDL::CreeSurface (const char* pathToBMP){
	
	if(strlen(pathToBMP)<5 || (strcmp(".bmp",pathToBMP+(strlen(pathToBMP)-4)) &&
		strcmp(".BMP",pathToBMP+(strlen(pathToBMP)-4)))) 
	{
		fprintf(stderr,"Erreur d’ouverture de fichier BMP:%s(extension incorrecte)\n",pathToBMP);
	}

	SDL_Surface * surface = SDL_LoadBMP(pathToBMP);

	if(!surface){
		fprintf(stderr,"Erreur d’ouverture de fichier BMP  : %s (Échec de SDL_LoadBMP)\n",pathToBMP);
	}

	return surface;
}





