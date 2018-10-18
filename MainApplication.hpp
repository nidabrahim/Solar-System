/******************************************************************************\
*     Copyright (C) 2017 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: MainApplication.h                                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#ifndef HEADER_MAINAPPLICATION_H
#define HEADER_MAINAPPLICATION_H

#include "WrapperSDL.hpp"
#include "Modele.hpp"
/**
 * CLASSE TOUTES LES DONNÉES DE L'APPLICATION
 * RÉALISE LES INITIALISATIONS
 * @warning Le gestionnaire de GUI initialise le contexte OpenGL
 * qui peut être utilisé par les contructeurs les paramètres de la vue
 * (choix du mode graphique, etc.)
 * Le gestionnaire de GUI initialise doit donc être initialisé avant
 * les paramètres de l'affichage.
 **/
class MainApplication{

public:
  /**
  * @param largeurFenetreInit largeur initiale de la fenêtre graphique
  * @param hauteurFenetreInit hauteur initiale de la fenêtre graphique
  **/
  MainApplication(int largeurFenetreInit, int hauteurFenetreInit,
                  const char* windowTitle, int argc, char** argv);

  ~MainApplication() = default;

private:
  // Gestionnaire de GUI et Contexte OpenGL
  WrapperSDL mWrapperSDL;

  // Variable globale initialisées par le constructeur par défaut
  Modele mModele;
};
#endif // HEADER_MAINAPPLICATION_H
