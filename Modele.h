#ifndef HEADER_MODELE_H
#define HEADER_MODELE_H

#include <cstdlib>
#include <vector>
#include "DisplayManager.h"
#include "Camera.h"
#include "AbstractScene.h"


class Modele {
	
	private:
	
		double mAngleRotation;
		double mVitesseRotation;
		float mNiveauGris;
		u_int32_t mLargeurFenetre;
		u_int32_t mHauteurFenetre;
		/** Gestionnaire de la vue (affichage) */
		DisplayManager mDisplayManager;
		Camera mCamera;
		std::vector<AbstractScene*> mScenes;

	public:

		Modele(u_int32_t largeurFenetre, u_int32_t hauteurFenetre);

		float getNiveauGris() const;
		
		u_int32_t getLargeurFenetre() const;
		
		u_int32_t getHauteurFenetre() const;
		
		Camera& getCamera();
		
		const Camera &getCamera() const;
		
		void render() const;
		
		void ApplyModelTransform() const;

		/** Mise à jour du modèle invoquée à chaque événement timer */
		void Update();
	  
		/** Mise à jour du modèle invoquée à chaque événement souris */
		void UpdateMouseMotion(int xShift, int yShift);

		void Redimensionnement(u_int32_t largeurFenetre, u_int32_t hauteurFenetre);


};
#endif
