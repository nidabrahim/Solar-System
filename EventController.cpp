/******************************************************************************\
*     Copyright (C) 2017 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: EventController.cpp                                                * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include <cstdlib>
#include <cstdio>

#include "MouseData.h"
#include "WrapperSDL.h"
#include "Modele.h"

// Initialisation des données de classe :
SDL_TimerID WrapperSDL::EventController::mTimerId;

void WrapperSDL::EventController::Init(SDL_Window *p_window, Modele *p_modele) {
  // Enregistrement d'un timer de raffraichissement de la vue
  mTimerId = SDL_AddTimer(20, CreateTimerRefreshFrame, (void *) p_modele);
  EventController::DoEventsLoop(p_window, p_modele);

}

void WrapperSDL::EventController::DoEventsLoop(SDL_Window *p_window, Modele *p_modele) {
  bool terminer = false;
  SDL_Event evenement; // union contenant un évennement

  while (!terminer) {
    while (SDL_PollEvent(&evenement)) {  // on défile les évennements
      // Gestion de l'événement et modification des variables
      terminer = Handle_SDL_Event(&evenement, p_window, p_modele);
    }
  }
}

Uint32 WrapperSDL::EventController::CreateTimerRefreshFrame(Uint32 interval, void *p_modele) {

  SDL_UserEvent userevent;
  userevent.type = SDL_USEREVENT;

  userevent.code = UserEventKinds::ANIMATION_TIMER;
  // Initialisation des données de l'événement nécessaire à l'affichage
  userevent.data1 = (void *) p_modele; // fonction de raffraichissement de la vue
  userevent.data2 = nullptr; // On ne l'utilise pas ici

  // On crée l'événement pour l'invocation suivante
  SDL_Event event;
  event.type = SDL_USEREVENT;
  event.user = userevent;
  SDL_PushEvent(&event); // On ajoute l'événement dans la file

  return interval;
}

/**
 * @brief Gestion d'un événement SDL extrait de la file
 * @param p_evenement données de l'événement
 * @param window  Fenêtre SDL (pour gérer les SDL_WINDOWEVENT)
 * @param p_ParamsAffichage instance de la classe Vue
 * @return true si l'événement est SDL_QUIT (fermeture de la fenêtre)
 */
bool WrapperSDL::EventController::Handle_SDL_Event(const SDL_Event *p_evenement,
                                                   SDL_Window *p_window, Modele *p_modele) {
  switch (p_evenement->type) { // suivant le type d'événement
    //////////////////////////////////////////////////////
    // Événements utilisateur via la souris
    case SDL_MOUSEBUTTONDOWN: // Enfoncement d'un bouton souris
      switch (p_evenement->button.button) {
        case SDL_BUTTON_LEFT :  // Bouton gauche
          MouseData::leftButtonPressed = true;
          MouseData::mousex = p_evenement->button.x; // mémorisation coordonnées souris
          MouseData::mousey = p_evenement->button.y; // mémorisation coordonnées souris
          break;
        case SDL_BUTTON_MIDDLE :  // Bouton gauche
          MouseData::middleButtonPressed = true;
          MouseData::mousex = p_evenement->button.x; // mémorisation coordonnées souris
          MouseData::mousey = p_evenement->button.y; // mémorisation coordonnées souris
          break;
        default:;
      }
      break;
    case SDL_MOUSEBUTTONUP: // Relachement d'un bouton souris
      switch (p_evenement->button.button) {
        case SDL_BUTTON_LEFT :  // Bouton gauche
          MouseData::leftButtonPressed = false;
          break;
        case SDL_BUTTON_MIDDLE :  // Bouton gauche
          MouseData::middleButtonPressed = false;
          break;
        default:;
      }
      break;
    case SDL_MOUSEMOTION: // Mouvement de la souris
      if (MouseData::leftButtonPressed || MouseData::middleButtonPressed) {
        // Mise à jour du modèle
        p_modele->UpdateMouseMotion(p_evenement->motion.x - MouseData::mousex,
                                    p_evenement->motion.y - MouseData::mousey);
        MouseData::mousex = p_evenement->motion.x; // enregistrement des nouvelles
        MouseData::mousey = p_evenement->motion.y; // coordonnées de la souris
      }
      break;
      break;
      //////////////////////////////////////////////////////
      // Événements perso : raffraîchissement de la vue
    case SDL_USEREVENT: // Événement timer
      // On teste la sorte d'événement SDL_USEREVENT (on peut en définir plusieurs)
      if (p_evenement->user.code == UserEventKinds::ANIMATION_TIMER) {
        // Récupération des données de l'événement nécessaire à l'affichage
        // Ici, commenté car redondant avec le paramètre p_modele de la méthode
        //Modele *p_modele = static_cast<Modele *>(p_evenement->user.data1);

        // Mise à jour du modèle et de la vue :
        p_modele->Update();

        // On envoie le buffer à l'écran à 50 FPS suivant le timer
        SDL_GL_SwapWindow(p_window);
      }
      break;
      //////////////////////////////////////////////////////
      // Événements utilisateur sur la fenêtre graphique
    case SDL_WINDOWEVENT: // La fenêtre graphique a changé
      int w, h;
      SDL_GetWindowSize(p_window, &w, &h); // récupération taille fenêtre
      // Application des changements sur le modèle de projection 3D->2D
      p_modele->Redimensionnement(w, h);
      break;
      //////////////////////////////////////////////////////
      // Fermeture de l'application
    case SDL_QUIT: // fermeture de la fenêtre
      return true;
      break;
    default:
      fprintf(stderr, "Événement non géré\n");
  }
  return false;
}
