#include "SystemeSolaire.h"
#include "RenderingGlobalRoutines.h"

SystemeSolaire::SystemeSolaire(int rayon, double angleRotationSun, double angleRotationSelf, double angleRotationMoon, double vitesseRotation)
				: mRayon(rayon), mAngleRotationSun(angleRotationSun), mAngleRotationSelf(angleRotationSelf), mAngleRotationMoon(angleRotationMoon), mVitesseRotation(vitesseRotation){}

SystemeSolaire::~SystemeSolaire(){}

void SystemeSolaire::render(){
	
	RenderingGlobalRoutines::DrawSolarSystem(*this);
}

int SystemeSolaire::GetRayon(){

	return this->mRayon;
}

double SystemeSolaire::GetAngleRotationSun(){
	
	return this->mAngleRotationSun;
}

double SystemeSolaire::GetAngleRotationSelf(){
	
	return this->mAngleRotationSelf;
}

double SystemeSolaire::GetAngleRotationMoon(){
	
	return this->mAngleRotationMoon;
}

double SystemeSolaire::GetVitesseRotation(){
	
	return this->mVitesseRotation;
}

void SystemeSolaire::SetAngleRotationSun(double angleRotationSun){
	
	this->mAngleRotationSun = angleRotationSun;
}

void SystemeSolaire::SetAngleRotationSelf(double angleRotationSelf){
	
	this->mAngleRotationSelf = angleRotationSelf;
}

void SystemeSolaire::SetAngleRotationMoon(double angleRotationMoon){

	this->mAngleRotationMoon = angleRotationMoon;
}

