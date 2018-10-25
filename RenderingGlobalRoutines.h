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

 /** Dessin du modèle avec OpenGL */
 static void DrawModel( Modele* modele = nullptr);
 
 static void DrawSolarSystem(SystemeSolaire & scene);
 
};

#endif
