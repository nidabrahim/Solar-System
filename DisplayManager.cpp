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
 // On efface les buffers ( é cran et profondeur )
	RenderingGlobalRoutines::InitView();
 // On se place dans l e repère du monde
	Camera::ClearModelView();
 // On appliquechangement de repère de l a camé ra dans l e ModelView
	modele.getCamera().ApplyCameraCoordinates ( );
 // On applique l a transformation du modèle
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
