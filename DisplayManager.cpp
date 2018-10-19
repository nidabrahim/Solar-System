#include <GLES3/gl3.h>
#include <GL/glut.h>

#include "DisplayManager.h"
#include "Modele.h"
#include "FramesData.h"
#include "RenderingGlobalRoutines.h"
#include "GeometricTransform.h"

DisplayManager::DisplayManager():mWindowChanged( true )
{
	FramesData::Init(); // I n i t i a l i s a t i o n du compteur de frames
	RenderingGlobalRoutines::Init(); // I n i t i a l i s a t i o n du fond et mode d ’ a f f i c h a g e
}

void DisplayManager::setWindowChanged() {
	mWindowChanged = true ;
}

void DisplayManager::Affichage( const Modele &modele ) {
 // Si l e s dimensions de l a fen ê t r e ont chang é ( ou à l ’ i n i t i a l i s a t i o n )
 if(mWindowChanged) {
	Redimensionnement(modele); 
	mWindowChanged = false ;
 }
 // On e f f a c e l e s b u f f e r s ( é cran et profondeur )
	RenderingGlobalRoutines::InitView();
 // On se place dans l e repère du monde
	Camera::ClearModelView();
 // On appliquechangement de repère de l a camé ra dans l e ModelView
	modele.getCamera().ApplyCameraCoordinates ( );
 // On applique l a transformation du modèle
	modele.ApplyModelTransform ( );
 // Dessin d ’ une th é i è r e
	RenderingGlobalRoutines::DrawModel(modele);
}

void DisplayManager::Redimensionnement(const Modele& modele){
	 GeometricTransform::Viewport(0, 0, (GLsizei) modele.getLargeurFenetre(), (GLsizei) modele.getHauteurFenetre());
	 Camera::ClearProjection ( );
	 modele.getCamera().ApplyPerspectiveProjection();
}
