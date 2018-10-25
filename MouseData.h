

#ifndef MOUSE_DATA_H
#define MOUSE_DATA_H

/** @brief Modèle pour la souris (interaction utilisateur)
 * Paramètres concernant la souris (état, vitesse, etc)
 */
struct MouseData{
  // Variables globales pour gestion de la souris
  static int mousex; // mémorise la dernière position de la souris
  static int mousey; // mémorise la dernière position de la souris
  static bool leftButtonPressed; // État des boutons de la souris
  static bool middleButtonPressed; // État des boutons de la souris
  static float vitesse; // facteur vitesse de la souris
};
#endif
