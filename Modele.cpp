#include <stdio.h>

#include "Modele.h"
#include "FramesData.h"
#include "GeometricTransform.h"


Modele::Modele(u_int32_t largeurFenetre, u_int32_t hauteurFenetre) :
		mAngleRotation(0.0),
		mVitesseRotation(0.3),
		mNiveauGris(0.0f),
		mLargeurFenetre(largeurFenetre),
        mHauteurFenetre(hauteurFenetre),
        mDisplayManager(),
		mCamera(50.0, mLargeurFenetre/(double)mHauteurFenetre, 0.01, 10000.0, 10.0, 7.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0)
		//mCamera(50.0, mLargeurFenetre/(double)mHauteurFenetre, 0.01, 10000.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0)
{
  FramesData::Init(); // Initialisation du compteur de frames
}

float Modele::getNiveauGris() const {
  return mNiveauGris;
}

u_int32_t Modele::getLargeurFenetre() const {
  return mLargeurFenetre;
}

u_int32_t Modele::getHauteurFenetre() const {
  return mHauteurFenetre;
}

 Camera& Modele::getCamera() {
   return mCamera;
}

const Camera &Modele::getCamera() const {
   return mCamera;
}

void Modele::ApplyModelTransform() const {
	// Rotation autour de l’axe vertical (voir initialisation caméra)
	GeometricTransform::Rotate(mAngleRotation, 0.0, 1.0, 0.0);
}

void Modele::Update() {
  // Affichage des Frames par seconde (FPS)
  if (FramesData::Update()) {
    fprintf(stderr, "%s\n", FramesData::getDescriptionFPS());
  }
  // Données d'environnement :
  mNiveauGris += 0.005f;
  if (mNiveauGris > 1.0f) {
    mNiveauGris = 0.0f;
  }
  mAngleRotation += mVitesseRotation;
  mDisplayManager.Affichage(*this); // Mise à jour de la vue
}

void Modele::UpdateMouseMotion(int /*xShift*/, int /*yShift*/) {
  // Pas de gestion du mouvement de la souris pour le moment
}

void Modele::Redimensionnement(u_int32_t largeurFenetre, u_int32_t hauteurFenetre) {
  mLargeurFenetre = largeurFenetre;
  mHauteurFenetre = hauteurFenetre;
  mCamera.UpdateAspect(largeurFenetre/(double)hauteurFenetre);
  mDisplayManager.setWindowChanged();
}
