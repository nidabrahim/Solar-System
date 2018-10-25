
#include <GLES3/gl3.h>
#include <GL/glut.h>

#include "WrapperSDL.h"

WrapperSDL::WrapperSDL(u_int32_t largeurFenetreInit, u_int32_t hauteurFenetreInit,
                       const char* windowTitle, int argc, char**argv):
        mWindowManager(largeurFenetreInit, hauteurFenetreInit, windowTitle),
        mModele(largeurFenetreInit, hauteurFenetreInit)
{
  glutInit(&argc, argv); // Initialisation de la GLUT
  EventController::Init(mWindowManager.getP_Window(), &mModele);
}

u_int32_t WrapperSDL::getTicks() {
  return SDL_GetTicks();
}
