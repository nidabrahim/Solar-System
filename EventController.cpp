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
#include <list>
#include <algorithm>
#include "MouseData.h"
#include "WrapperSDL.h"
#include "Modele.h"

#define VITESSEKEY 10
#define VITESSEMOU 100
#define VITESSEROT 5

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

bool managePressedKeys(std::list<int> keys, Modele *p_ParamsAffichage){
	bool res = std::find(keys.begin(), keys.end(), SDLK_q) != keys.end();
	if (res){
		exit(0);
	}

	if(std::find(keys.begin(), keys.end(), SDLK_LSHIFT) != keys.end() ||
		std::find(keys.begin(), keys.end(), SDLK_RSHIFT) != keys.end()){
			// MAJ PRESSED
		if(std::find(keys.begin(), keys.end(), SDLK_x) != keys.end()){
			p_ParamsAffichage->getCamera().GetPosition()[0] += VITESSEKEY;
		}
		if(std::find(keys.begin(), keys.end(), SDLK_y) != keys.end()){
			p_ParamsAffichage->getCamera().GetPosition()[1] += VITESSEKEY;
		}
		if(std::find(keys.begin(), keys.end(), SDLK_z) != keys.end()){
			p_ParamsAffichage->getCamera().GetPosition()[2] += VITESSEKEY;
		}
		if(std::find(keys.begin(), keys.end(), SDLK_a) != keys.end()){
			p_ParamsAffichage->getCamera().UpdateAngle(p_ParamsAffichage->getCamera().GetAngleOuvertureY() + VITESSEKEY);
		}

/*
		if(std::find(keys.begin(), keys.end(), SDLK_a) != keys.end()){
			p_ParamsAffichage->mCamera.SetAzimuth(p_ParamsAffichage->mCamera.GetAzimuth() + VITESSEROT);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_e) != keys.end()){
			p_ParamsAffichage->mCamera.SetElevation(p_ParamsAffichage->mCamera.GetElevation() + VITESSEROT);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_i) != keys.end()){
			p_ParamsAffichage->mLight.SetIntensities(p_ParamsAffichage->mLight.mIntensity+0.1f);
			p_ParamsAffichage->mLight.ApplyLightIntensities();
		}

		if(std::find(keys.begin(), keys.end(), SDLK_b) != keys.end()){
			p_ParamsAffichage->mModele.changeBrillance(p_ParamsAffichage->mModele.mBrillance + 8.0f);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_o) != keys.end()){
			p_ParamsAffichage->mModele.changeRefAmbiante(p_ParamsAffichage->mModele.mReflexionAmbiante + 0.1f);
		}
*/
	}else{
/*
		if(std::find(keys.begin(), keys.end(), SDLK_a) != keys.end()){
			p_ParamsAffichage->mCamera.SetAzimuth(p_ParamsAffichage->mCamera.GetAzimuth() - VITESSEROT);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_e) != keys.end()){
			p_ParamsAffichage->mCamera.SetElevation(p_ParamsAffichage->mCamera.GetElevation() - VITESSEROT);
		}
*/
		if(std::find(keys.begin(), keys.end(), SDLK_x) != keys.end()){
			p_ParamsAffichage->getCamera().GetPosition()[0] -= VITESSEKEY;
		}
		if(std::find(keys.begin(), keys.end(), SDLK_y) != keys.end()){
			p_ParamsAffichage->getCamera().GetPosition()[1] -= VITESSEKEY;
		}
		if(std::find(keys.begin(), keys.end(), SDLK_z) != keys.end()){
			p_ParamsAffichage->getCamera().GetPosition()[2] -= VITESSEKEY;
		}
		if(std::find(keys.begin(), keys.end(), SDLK_a) != keys.end()){
			p_ParamsAffichage->getCamera().UpdateAngle(p_ParamsAffichage->getCamera().GetAngleOuvertureY() - VITESSEKEY);
		}

/*

		if(std::find(keys.begin(), keys.end(), SDLK_i) != keys.end()){
			p_ParamsAffichage->mLight.SetIntensities(p_ParamsAffichage->mLight.mIntensity-0.1f);
			p_ParamsAffichage->mLight.ApplyLightIntensities();
		}

		if(std::find(keys.begin(), keys.end(), SDLK_b) != keys.end()){
			p_ParamsAffichage->mModele.changeBrillance(p_ParamsAffichage->mModele.mBrillance - 8.0f);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_o) != keys.end()){
			p_ParamsAffichage->mModele.changeRefAmbiante(p_ParamsAffichage->mModele.mReflexionAmbiante - 0.1f);
		}
*/
	}

	if(std::find(keys.begin(), keys.end(), SDLK_UP) != keys.end()){
		p_ParamsAffichage->getCamera().GetPosition()[1] += VITESSEKEY;
	}
	if(std::find(keys.begin(), keys.end(), SDLK_DOWN) != keys.end()){
		p_ParamsAffichage->getCamera().GetPosition()[1] -= VITESSEKEY;
	}

	if(std::find(keys.begin(), keys.end(), SDLK_RIGHT) != keys.end()){
		p_ParamsAffichage->getCamera().GetPointDeVisee()[1] -= VITESSEKEY;
	}

	if(std::find(keys.begin(), keys.end(), SDLK_LEFT) != keys.end()){
		p_ParamsAffichage->getCamera().GetPointDeVisee()[1] += VITESSEKEY;
	}

	if(std::find(keys.begin(), keys.end(), SDLK_e) != keys.end()){
		p_ParamsAffichage->getCamera().Zoom(true);
	}

	if(std::find(keys.begin(), keys.end(), SDLK_r) != keys.end()){
		p_ParamsAffichage->getCamera().Zoom(false);
	}

	return res;
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
bool WrapperSDL::EventController::Handle_SDL_Event(const SDL_Event *p_evenement,SDL_Window *p_window, Modele *p_modele) {
	
	static std::list<int> keys;
	std::list<int>::iterator toRemove;
	bool res = false;
													   
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
      
      // Evenement clavier
      case SDL_KEYDOWN:
		keys.push_back(p_evenement->key.keysym.sym);
		keys.unique();
		res = managePressedKeys(keys, p_modele);
		printf("La touche %s a été enfoncée\n",SDL_GetKeyName(p_evenement->key.keysym.sym));
		switch(p_evenement->key.keysym.sym) {
			case SDLK_LEFT : /* touche flèche à gauche */
			printf("La touche LEFT a été enfoncée\n");
				/*niveauDeGris −= 0.05f;
				if(niveauDeGris < 0.0f)
					niveauDeGris = 0.0f;*/
			break ;
			
			case SDLK_RIGHT : /* touche f l è c h e à d r o i t e */
			printf("La touche RIGHT a été enfoncée\n");
				/*niveauDeGris += 0.05 f ;
				i f ( niveauDeGris > 1.0 f )
					niveauDeGris = 1.0 f ;*/
			break ;
			
			case SDLK_q : /* touche ’ q ’ , on q u i t t e */
				 
			break ;
			default :
 			break ;
		}
		break;
		
	case SDL_KEYUP:
	   	toRemove = std::find(keys.begin(), keys.end(), p_evenement->key.keysym.sym);
    	if(toRemove != keys.end()){
    		keys.erase(toRemove);
    	}
		break;
    
		////////////////////////////////////////////////////////
      // Fermeture de l'application
    case SDL_QUIT: // fermeture de la fenêtre
      return true;
      break;
    default:
      fprintf(stderr, "Événement non géré\n");
  }
  return res;
}
