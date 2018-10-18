#ifndef HEADER_DISPLAY_MANAGER_H
#define HEADER_DISPLAY_MANAGER_H

#include <GLES3/gl3.h>
#include <GL/glut.h>

class Modele;
/**
 * CLASSE DE GESTION DE L'AFFICHAGE (accède au modèle et affiche les données)
 */
class DisplayManager{
  /** true si les dimensions de la fenêtre ont changé.
      Indique que la matrice de projection doit être redéfinie */
  bool mWindowChanged;
public:
   /** @brief  Constructeur prenant la géométrie de la fenêtre
   * Initialise les données spécifiques à l'affichage.
   **/
  DisplayManager();

  /** Notifie la vue que la perspective doit être reconstruite avant affichage */
  void setWindowChanged();

  /** @brief Méthode d'affichage des données du modèle
   * @param modele Modèle contenant les données à afficher
   **/
  void Affichage(const Modele& modele);

  /** @brief Réglage du cadrage pour la vue
   * Doit être rappelée si la taille de la vue change (SDL_WINDOWEVENT)
   * @param modele Modèle de données contenant les informations sur le viewport
   * (cadre 2D de la vue) et la projection (orthogonale, perspective, etc.)
   */
  void Redimensionnement(const Modele& modele);
};
#endif
