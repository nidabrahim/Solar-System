#include <GLES3/gl3.h>
#include <GL/glut.h>

#include "RenderingGlobalRoutines.h"
#include "Modele.h"


void RenderingGlobalRoutines::Init(){
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	// On a c t i v e l ’ é limination des p a r t i e s cach é es
	glEnable(GL_DEPTH_TEST);
}

void RenderingGlobalRoutines::InitView(){
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) ;
}

void RenderingGlobalRoutines::DrawModel(const Modele& /* modele */ ){
	// Dessin de l a mondialement c é l è b r e th é i è r e GLUT
	glutWireTeapot(1);
}
