#ifndef HEADER_MODELE_H
#define HEADER_MODELE_H

#include <cstdlib>
#include <vector>
#include "DisplayManager.h"
#include "Camera.h"
#include "AbstractScene.h"
#include "texture/TextureManagerSDL.h"


class Modele {
	
	private:
	
		double mAngleRotation;
		double mVitesseRotation;
		float mNiveauGris;
		u_int32_t mLargeurFenetre;
		u_int32_t mHauteurFenetre;
		DisplayManager mDisplayManager;
		Camera mCamera;
		std::vector<AbstractScene*> mScenes;
		TextureManagerSDL mTexture;

	public:

		Modele(u_int32_t largeurFenetre, u_int32_t hauteurFenetre);

		float getNiveauGris() const;
		
		u_int32_t getLargeurFenetre() const;
		
		u_int32_t getHauteurFenetre() const;
		
		Camera& getCamera();
		
		const Camera &getCamera() const;
		
		void render() const;
		
		void ApplyModelTransform() const;
		
		const TextureManagerSDL &getTexture() const;

		/** Mise à jour du modèle invoquée à chaque événement timer */
		void Update();
	  
		/** Mise à jour du modèle invoquée à chaque événement souris */
		void UpdateMouseMotion(int xShift, int yShift);

		void Redimensionnement(u_int32_t largeurFenetre, u_int32_t hauteurFenetre);


};
#endif
