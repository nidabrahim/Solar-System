

#ifndef HEADER_FRAME_DATA_H
#define HEADER_FRAME_DATA_H

#include <cstdlib> // pour les entier calibrés (u_int32_t, int64_t...)
/**
 * DONNÉES POUR LE TIMER ET LE CALCUL DES FRAMES PER SECONDS
*/
class FramesData{
  static uint mNbSeconds; // compteur de secondes
  static u_int64_t mNbFrames;
  static u_int64_t mLastNbFrames; // compteur de frames
  static u_int64_t mFps; // frames par secondes
  
  private: static char mDescriptionFPS[200];
  
public:
  
  // Initialisation de la description des FPS
  static void Init();
  
  /**
   * Met à jour l'information du Frame Rate
   * @return true si une mise à jour a eu lieu (chaque seconde)
   */
  static bool Update();
  
  /**
   * @return description des numéro de frame, durée, et FPS
   */
  static const char* getDescriptionFPS();

};
#endif
