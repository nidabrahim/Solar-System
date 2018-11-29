#ifndef HEADER_RENDERING_INIT_H
#define HEADER_RENDERING_INIT_H

#include "SystemeSolaire.h"
#include "Voiture.h"
#include <cstdint> 

class Modele ;

 /**
 * MÉTHODES CONCERNANT LES MODÈLES DE RENDU
 */

struct RenderingGlobalRoutines {
 
 /** Initialiseles paramètres de rendu de la scène */
 static void Init();

 /** Réinitialise la vue ( efface l’écran ) avant raffraîchissement */
 static void InitView();
 
 static void ApplyPointLightPosition(int32_t lightId, const float position[4]);
 
 static void ApplyPointLightIntensity(int32_t lightId, const float diffuseIntensity[4], const float specularIntensity[4]);
 
 static void DisablePointLight(int32_t lightId);
 
 static void ApplyMaterial(Material material);

 /** Dessin du modèle Theiere avec OpenGL */
 static void DrawTheiere( Modele* modele = nullptr);
 
 /** Dessin d'un modèle Systeme solaire avec OpenGL */
 static void DrawSolarSystem(SystemeSolaire & scene);
 
  /** Dessin d'un modèle ed roue avec OpenGL */
 static void DrawRoue(Voiture & scene);
 
   /** Dessin d'un modèle d'essieu avec OpenGL */
 static void DrawEssieu(double longueur);
 
   /** Dessin d'un modèle de corps de voiture avec OpenGL */
 static void DrawCorps(Voiture & scene);
 
 
};

#endif
