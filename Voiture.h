#ifndef HEADER_VOITURE_HPP
#define HEADER_VOITURE_HPP

#include "AbstractScene.h"


class Voiture : public AbstractScene {
	
	private:
		double mVitesseRoue;	/// increment de vitesse de rotation des roues de la voiture
		int mStep;						/// etat de la rotation des roues
		const int maxStep;		/// etat max de la rotaiton des roues

	public:
		Voiture(double vitesseRoue = 0.1): mVitesseRoue(vitesseRoue), mStep(0), maxStep((int)(360.0/vitesseRoue)) {}
		~Voiture() {}

		void drawRoue();
		void drawEssieu(double longueur);
		void drawCorps();
		void render();
};

#endif
