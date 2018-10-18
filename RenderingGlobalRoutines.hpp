#ifndef HEADER_RENDERING_INIT_H
#define HEADER_RENDERING_INIT_H



class Modele ;

 /**
 * MÉTHODES CONCERNANT LES MODÈLES DE RENDU
 */

struct RenderingGlobalRoutines {
 
 /** I n i t i a l i s e l e s paramètres de rendu de l a scène */
 static void Init();

 /** Ré i n i t i a l i s e l a vue ( e f f a c e l ’ é cran ) avant r a f f r a î chissement */
 static void InitView();

 /** Dessin du modèle avec OpenGL */
 static void DrawModel(const Modele& modele);
 
};

#endif
