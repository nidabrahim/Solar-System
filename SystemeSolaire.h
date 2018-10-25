#ifndef HEADER_SYSTEMESCOLAIRE_HPP
#define HEADER_SYSTEMESCOLAIRE_HPP

#include "AbstractScene.h"

class SystemeSolaire : public AbstractScene {

	private:
		int mRayon;
		double mAngleRotationSun;
		double mAngleRotationSelf;
		double mAngleRotationMoon;
		double mVitesseRotation;
	
	public:
		SystemeSolaire(int rayon = 6, double angleRotationSun = 0.0, double angleRotationSelf = 0, double angleRotationMoon = 0, double vitesseRotation = 0.3);
		~SystemeSolaire();
		void render();
		
		int GetRayon();
		double GetAngleRotationSun();
		double GetAngleRotationSelf();
		double GetAngleRotationMoon();
		double GetVitesseRotation();
		
		void SetAngleRotationSun(double angleRotationSun);
		void SetAngleRotationSelf(double angleRotationSelf);
		void SetAngleRotationMoon(double angleRotationMoon);

};

#endif
