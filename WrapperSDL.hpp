/******************************************************************************\
*     Copyright (C) 2017 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: WrapperSDL.h                                                       * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#ifndef HEADER_WRAPPER_SDL_H
#define HEADER_WRAPPER_SDL_H

#include <SDL2/SDL.h>

#include "Modele.hpp"
/**
 * Classe Wrapper pour SDL et assurant les fonctionnalités de la GUI
 */
class WrapperSDL{

public:
  /** Construit la fenêtre graphique aux dimensions, avec le contexte OpenGL */
  WrapperSDL(u_int32_t largeurFenetreInit, u_int32_t hauteurFenetreInit,
             const char* windowTitle, int argc, char**argv);
  /** @return the number of milliseconds since the SDL library initialized. */
  static u_int32_t getTicks();

  ~WrapperSDL() = default;

private:
  /** @brief Gestionnaire de la fenêtre graphique et du contexte OpenGL
   * Classe imbriquée
   */
  class WindowManager{

  public:
    /** @brief Fonction d'initialisation de la fenêtre SDL
      @param windowWidth largeur de la fenêtre en pixels
      @param windowWidth largeur de la fenêtre en pixels
      @param windowTitle Titre de la fenêtre dans sa barre de titre
    */
    WindowManager(int largeurFenetreInit, int hauteurFenetreInit,
                  const char* windowTitle);

    SDL_Window* getP_Window() const;

    /** Destruction : Libération des ressources SDL et OpenGL */
    ~WindowManager();

  private:
    /** Adresse de la fenêtre SDL */
    SDL_Window *mP_Window;
    /** Adresse du contexte OpenGL */
    SDL_GLContext *mP_GlContext;

    /** @brief Fonction d'initialisation de la fenêtre SDL
      @param windowWidth largeur de la fenêtre en pixels
      @param windowWidth largeur de la fenêtre en pixels
      @param windowTitle Titre de la fenêtre dans sa barre de titre
    */
    static SDL_Window * init_SDL_Window(int windowWidth, int windowHeight, const char* windowTitle);

    // On interdit explicitement la recopie
    WindowManager(const WindowManager&) = delete;
    WindowManager & operator=(const WindowManager&) = delete;
  };

  /** @brief Classe Controleur d'événements utilisateur et timer.
   * Classe imbriquée.
   */
  class EventController{

  public:
    /** Initialisation du timer et démarrage de la boucle d'événements */
    static void Init(SDL_Window* p_window, Modele* p_modele);

  private:
    /** Type pour représenter les sortes d'événements de type SDL_USEREVENT */
    enum UserEventKinds{
      ANIMATION_TIMER=0
    };

    /**@brief Gestion d'un événement SDL extrait de la file
     * @param p_evenement données de l'événement
     * @param window  Fenêtre SDL (pour gérer les SDL_WINDOWEVENT)
     * @param p_ParamsAffichage instance de la classe Vue
     * @return true si l'événement est SDL_QUIT (fermeture de la fenêtre)
     */
    static bool Handle_SDL_Event(const SDL_Event *p_evenement, SDL_Window *p_window, Modele *p_modele);

    /** Boucle d'attente des événements
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT)
     * @param p_ParamsAffichage instance de la classe Vue
     **/
    static void DoEventsLoop(SDL_Window *window, Modele *p_modele);

    /**
     * @brief Callback du timer de raffraichissement de la vue
     * @see http://sdl.beuc.net/sdl.wiki/SDL_AddTimer
     * @param interval intervalle de temps en millisecondes entre deux invocations
     * @param m_modele adresse du modèle de données de l'application castée en void*
     */
    static u_int32_t CreateTimerRefreshFrame(Uint32 interval, void* p_modele);

    /** Identifiant du timer d'annimation */
    static SDL_TimerID mTimerId; // Au cas où on ait besoin de modifier
  };

  /** Instance de la classe gérant la fenêtre graphique */
  WindowManager mWindowManager;
  /** Instance du modèle de données de l'application */
  Modele mModele;
};
#endif
