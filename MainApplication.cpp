/******************************************************************************\
*     Copyright (C) 2017 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: MainApplication.cpp                                                * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "MainApplication.hpp"

MainApplication::MainApplication(int largeurFenetreInit, int hauteurFenetreInit,
                                 const char *windowTitle, int argc,
                                 char **argv) :
        mWrapperSDL(largeurFenetreInit, hauteurFenetreInit,
                    windowTitle, argc, argv),
        mModele(largeurFenetreInit, hauteurFenetreInit)
{}
