

#include <SDL2/SDL_opengl.h>
#include <GLES3/gl3.h>

#include "WrapperSDL.h"

WrapperSDL::WindowManager::WindowManager(int largeurFenetreInit, int hauteurFenetreInit,
                                         const char* windowTitle)
// Initialisation d'une fenêtre SDL
        :mP_Window(init_SDL_Window(largeurFenetreInit, hauteurFenetreInit,
                                 windowTitle)),
        // Création du contexte OpenGL associé à cette fenêtre
         mP_GlContext(new SDL_GLContext(SDL_GL_CreateContext(mP_Window)))
{}

SDL_Window * WrapperSDL::WindowManager::init_SDL_Window(int windowWidth, int windowHeight, const char* windowTitle){
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);
  SDL_Init(SDL_INIT_VIDEO);

  // Le double buffering permet les animations temps réel
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_Window *window = SDL_CreateWindow(windowTitle,
          // Fenêtre centrée sur l'écran numéro 1 (cas de plusieurs écrans...)
                                        SDL_WINDOWPOS_CENTERED_DISPLAY(1) , SDL_WINDOWPOS_CENTERED_DISPLAY(1),
                                        windowWidth, windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  return window;
}

WrapperSDL::WindowManager::~WindowManager(){
  SDL_GL_DeleteContext(*mP_GlContext);
  SDL_DestroyWindow(mP_Window);
  SDL_Quit();
  delete mP_GlContext;
}

SDL_Window *WrapperSDL::WindowManager::getP_Window() const {
  return mP_Window;
}
