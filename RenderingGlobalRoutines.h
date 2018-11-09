#ifndef HEADER_RENDERING_INIT_H
#define HEADER_RENDERING_INIT_H

#include "SystemeSolaire.h"

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
 
};

#endif
