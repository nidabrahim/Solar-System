/******************************************************************************\
*     Copyright (C) 2017 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: MouseData.cpp                                                      * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "MouseData.hpp"

// Initialisation des données de classe
int MouseData::mousex = 0;
int MouseData::mousey = 0;
bool MouseData::leftButtonPressed = false;
bool MouseData::middleButtonPressed = false;
float MouseData::vitesse = 0.2f;

