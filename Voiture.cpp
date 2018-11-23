#include "Voiture.h"
#include "RenderingGlobalRoutines.h"



void Voiture::drawRoue(){
	
	RenderingGlobalRoutines::DrawRoue(*this);
}

void Voiture::drawEssieu(double longueur){

	RenderingGlobalRoutines::DrawEssieu(longueur);
}

void Voiture::drawCorps(){

	RenderingGlobalRoutines::DrawCorps(*this);
}

void Voiture::render(){
	
	drawCorps();
	mStep = (mStep+1) % maxStep;
}
