/******************************************************************************\
*     Copyright (C) 2017 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: main.cpp                                                           * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "MainApplication.h"

/////////////////////////////////////////////////////////////////
// PROGRAMME PRINCIPAL
/////////////////////////////////////////////////////////////////

int main(int argc, char**argv)
{  
  MainApplication myApp(700, 700, "Mon Application SDL/OpenGL",argc, argv);
  return 0;
}
