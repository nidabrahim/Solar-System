#include "texture_object.hpp"

#include <stdexcept>
#include <SDL/SDL_image.h>
#include <unistd.h>

/**
 * @brief Create cube texture
 * 
 * @return GLuint 
 */
GLuint TextureObject::createGLCubeTexture() {
	GLuint texture;

	glEnable(GL_TEXTURE_CUBE_MAP);
	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

	cubeTextureParameters();

	return texture;
}

/**
 * @brief Create 1D texture
 * 
 * @return GLuint 
 */
GLuint TextureObject::createGL1DTexture() {
	GLuint texture;

	glEnable(GL_TEXTURE_1D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_1D, texture);

	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return texture;
}

/**
 * @brief Set texture parameters
 * 
 */
void TextureObject::cubeTextureParameters() {
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_BASE_LEVEL, 0); 
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAX_LEVEL, 0); 
}

GLuint TextureObject::create1DTexture(string path) {
	SDL_Surface *surface = loadTextureImage(path);

	GLuint texture = createGL1DTexture();

	tex_info info = getTextureParams(surface);


	glTexImage1D(
			GL_TEXTURE_1D,
			0,
			info.n_of_colors,
			surface->w,
			0,
			info.texture_format,
			GL_UNSIGNED_BYTE,
			surface->pixels
	);

	SDL_FreeSurface(surface);
	return texture;
}

GLuint TextureObject::createCubeTexture(
			string x_pos,
			string x_neg,
			string y_pos,
			string y_neg,
			string z_pos,
			string z_neg
) {
	SDL_Surface *surface_x_pos = loadTextureImage(x_pos);
	SDL_Surface *surface_x_neg = loadTextureImage(x_neg);
	SDL_Surface *surface_y_pos = loadTextureImage(y_pos);
	SDL_Surface *surface_y_neg = loadTextureImage(y_neg);
	SDL_Surface *surface_z_pos = loadTextureImage(z_pos);
	SDL_Surface *surface_z_neg = loadTextureImage(z_neg);

	GLuint texture = createGLCubeTexture();

	assignCubeTextureImages(
			surface_x_pos,
            surface_x_neg,
            surface_y_pos,
            surface_y_neg,
            surface_z_pos,
            surface_z_neg
	);

	SDL_FreeSurface(surface_x_pos);
	SDL_FreeSurface(surface_x_neg);
	SDL_FreeSurface(surface_y_pos);
	SDL_FreeSurface(surface_y_neg);
	SDL_FreeSurface(surface_z_pos);
	SDL_FreeSurface(surface_z_neg);

	return texture;
}

SDL_Surface *TextureObject::loadTextureImage(string path) {
	SDL_Surface *surf;
	SDL_RWops *rwop;

	rwop = SDL_RWFromFile(path.c_str(), "rb");
	if (!rwop) {
		throw std::runtime_error("Could not load texture file " + path);
	}
	surf = IMG_LoadPNG_RW(rwop);

	if (!surf) {
		throw std::runtime_error("Could not load texture " + path);
	}

	delete rwop;

	return surf;
}

void TextureObject::assign2DImage(SDL_Surface *surface, GLenum target) {
	tex_info info = getTextureParams(surface);

	glTexImage2D(
			target,
			0,
			info.n_of_colors,
			surface->w,
			surface->h,
			0,
			info.texture_format,
			GL_UNSIGNED_BYTE,
			surface->pixels
	);
}

void TextureObject::assignCubeTextureImages(
	SDL_Surface * surface_x_pos,
	SDL_Surface * surface_x_neg,
	SDL_Surface * surface_y_pos,
	SDL_Surface * surface_y_neg,
	SDL_Surface * surface_z_pos,
	SDL_Surface * surface_z_neg
) {

	assign2DImage(surface_x_pos, GL_TEXTURE_CUBE_MAP_POSITIVE_X);
	assign2DImage(surface_x_neg, GL_TEXTURE_CUBE_MAP_NEGATIVE_X);
	assign2DImage(surface_y_pos, GL_TEXTURE_CUBE_MAP_POSITIVE_Y);
	assign2DImage(surface_y_neg, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y);
	assign2DImage(surface_z_pos, GL_TEXTURE_CUBE_MAP_POSITIVE_Z);
	assign2DImage(surface_z_neg, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z);

}

TextureObject::tex_info TextureObject::getTextureParams(SDL_Surface *surface) {
	GLint n_of_colors;
	#pragma GCC diagnostic ignored "-Wuninitialized"
	GLenum texture_format = GL_RGBA;
	
	n_of_colors = surface->format->BytesPerPixel;
	if (n_of_colors == 4)  { 
		if (surface->format->Rmask == 0x000000ff) {
			texture_format = GL_RGBA;
		}
		else {
			texture_format = GL_BGRA;
		}
	} 
	else if (n_of_colors == 3) {  
		if (surface->format->Rmask == 0x000000ff) {
			texture_format = GL_RGB;
		}
		else {
			texture_format = GL_BGR;
		}
	} else {
		throw std::runtime_error("Image seems not to be true color");
	}

	tex_info info;
	info.texture_format = texture_format;
	info.n_of_colors = n_of_colors;

	return info;
}
