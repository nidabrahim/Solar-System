#include <GLES3/gl3.h>
#include <GL/glut.h>

#include "RenderingGlobalRoutines.h"
#include "Modele.h"
#include "GeometricTransform.h"
#include <cmath>
#include <stdio.h>


void RenderingGlobalRoutines::Init(){
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	// On active l’élimination des parties cachées
	glEnable(GL_DEPTH_TEST);
}

void RenderingGlobalRoutines::InitView(){
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) ;
}

void RenderingGlobalRoutines::DrawTheiere( Modele *  modele ){
/*
	glutWireTeapot(5);
*/
	glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        fprintf(stderr,"Before SelectTexture2D\n");
        modele->getTexture().SelectTexture2D();
        fprintf(stderr,"After SelectTexture2D\n");
            glTexCoord2f(0.0,0.0);  glVertex3f(-3.0,-2.0 ,0.0);
            glTexCoord2f(1.0,0.0);  glVertex3f(3.0,-2.0,0.0);
            glTexCoord2f(1.0,1.0);  glVertex3f(3.0,2.0,0.0);
            glTexCoord2f(0.0,1.0);  glVertex3f(-3.0 ,2.0 ,0.0);
        glEnd();
    glPopMatrix();
	
}

void RenderingGlobalRoutines::DrawSolarSystem(SystemeSolaire & scene){ 
	
	glColor4f (1.0, 1.0, 0, 1);
	glPushMatrix();
	glutSolidSphere(scene.GetRayon(), 70, 70);
	
	glRotatef((GLfloat)scene.GetAngleRotationSun(), 0.0, 1.0, 0.0);
	glTranslatef((GLfloat)-scene.GetRayon()*3, 0.0, 0.0);
	glPushMatrix();
	
	glPushMatrix();
	glRotatef((GLfloat) scene.GetAngleRotationSelf(), 0.0, 1.0, 0.0);
	glColor3f (0, 0, 1);
	glutWireSphere(scene.GetRayon()/2, 70, 70);
	glPopMatrix();
		
	glPushMatrix();
	glRotatef((GLfloat)scene.GetAngleRotationMoon(), 0.0, 1.0, 0.0);
	glTranslatef((GLfloat)-scene.GetRayon(), 0.0, 0.0);                       
    glutWireSphere(scene.GetRayon()/6, 10, 8);             
    glPopMatrix();
    
    scene.SetAngleRotationMoon( fmod((scene.GetAngleRotationMoon() + scene.GetVitesseRotation()*20),360.0) );
	scene.SetAngleRotationSelf( fmod((scene.GetAngleRotationSelf() + scene.GetVitesseRotation()*4),360.0) );
	scene.SetAngleRotationSun( fmod((scene.GetAngleRotationSun() + scene.GetVitesseRotation()),360.0) );
	glPopMatrix();
	
	glPopMatrix();

}
