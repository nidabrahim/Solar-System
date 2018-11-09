#include <GLES3/gl3.h>
#include <GL/glut.h>

#include "DisplayManager.h"
#include "Modele.h"
#include "FramesData.h"
#include "RenderingGlobalRoutines.h"
#include "GeometricTransform.h"

DisplayManager::DisplayManager():mWindowChanged( true )
{
	FramesData::Init(); // Initialisation du compteur de frames
	RenderingGlobalRoutines::Init(); // Initialisation du fond et mode d’affichage
}

void DisplayManager::setWindowChanged() {
	mWindowChanged = true ;
}

void DisplayManager::Affichage( const Modele &modele ) {
 // Si les dimensions de la fenêtre ont changé ( ou à l’initialisation )
 if(mWindowChanged) {
	Redimensionnement(modele); 
	mWindowChanged = false ;
 }
 // On efface les buffers ( écran et profondeur )
	RenderingGlobalRoutines::InitView();
 // On se place dans le repère du monde
	Camera::ClearModelView();
 // On applique changement de repère de la caméra dans le ModelView
	modele.getCamera().ApplyCameraCoordinates ( );
	
	// Positionnement des caméras qui sont dans le repère du monde
	modele.mScenes[0]->getLightSources().ApplyLightPositions(LightSourceData::TypeRepere::MONDE);
	
	// On applique les intensités des sources et on active les sources
	modele.mScenes[0]->getLightSources().ApplyLightIntensities();
	
	//Définition des propiétés matérielles
	RenderingGlobalRoutines::ApplyMaterial(modele.mScenes[0]->getDefaultMaterial());
	
 // On applique la transformation du modèle
	modele.ApplyModelTransform ( );
 // Dessin d’une théière
	//RenderingGlobalRoutines::DrawModel(modele);
	modele.render();
}

void DisplayManager::Redimensionnement(const Modele& modele){
	 GeometricTransform::Viewport(0, 0, (GLsizei) modele.getLargeurFenetre(), (GLsizei) modele.getHauteurFenetre());
	 Camera::ClearProjection ( );
	 modele.getCamera().ApplyPerspectiveProjection();
}
