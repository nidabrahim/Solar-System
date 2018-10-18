/******************************************************************************\
*     Copyright (C) 2017 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: WrapperSDL.cpp                                                     * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include <GLES3/gl3.h>
#include <GL/glut.h>

#include "WrapperSDL.hpp"

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
