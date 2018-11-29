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
	// On active l'éclairage
	glEnable(GL_LIGHTING);
}

void RenderingGlobalRoutines::InitView(){
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) ;
}

static void RenderingGlobalRoutines::ApplyPointLightPosition(int32_t lightId, const float position[4]){
	glLightfv(lightId, GL_POSITION, position);
}
 
static void RenderingGlobalRoutines::ApplyPointLightIntensity(int32_t lightId, const float diffuseIntensity[4], const float specularIntensity[4]){
	glLightfv(lightId, GL_DIFFUSE, diffuseIntensity);
	glLightfv(lightId, GL_SPECULAR, specularIntensity);
	glEnable(lightId);
}
 
static void RenderingGlobalRoutines::DisablePointLight(int32_t lightId){
	glDisable (lightId);
}
 
static void RenderingGlobalRoutines::ApplyMaterial(Material material){
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material.getAmbient());
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material.getDiffuse());
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material.getSpecular());
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material.getShininess());
}

void RenderingGlobalRoutines::DrawTheiere( Modele * /* modele */ ){

	glutWireTeapot(5);
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
	//glColor4f (0.4, 0.5, 0.6, 1);                       
    glutWireSphere(scene.GetRayon()/6, 10, 8);             
    glPopMatrix();
    
    scene.SetAngleRotationMoon( fmod((scene.GetAngleRotationMoon() + scene.GetVitesseRotation()*20),360.0) );
	scene.SetAngleRotationSelf( fmod((scene.GetAngleRotationSelf() + scene.GetVitesseRotation()*4),360.0) );
	scene.SetAngleRotationSun( fmod((scene.GetAngleRotationSun() + scene.GetVitesseRotation()),360.0) );
	glPopMatrix();
	
	glPopMatrix();

}

void RenderingGlobalRoutines::DrawRoue(Voiture & scene){
	 
	glPushMatrix();
		GeometricTransform::Rotate(0, 1, 0, 90);
		GeometricTransform::Rotate(0, 0, 1, scene.mStep * scene.mVitesseRoue);
		gluCylinder(gluNewQuadric(),
		 	5,	//base,
		 	5,  	//top,
		 	0.5, 	//height,
		 	12, 	//slices,
		 	12  	//stacks
		 );
	glPopMatrix();	 
}
 
void RenderingGlobalRoutines::DrawEssieu(double longueur){
	glPushMatrix();
		GeometricTransform::Translate(-longueur/2, 0, 0);
		GeometricTransform::Rotate(0, 1, 0, 90);
		gluCylinder(gluNewQuadric(),
		 	0.5,		//base,
		 	0.5,  	//top,
		 	longueur, 	//height,
		 	8, 	//slices,
		 	8  	//stacks
		 );
	glPopMatrix();

	// Roue gauche
	glPushMatrix();
		GeometricTransform::Translate(longueur/2, 0, 0);
		DrawRoue();
	glPopMatrix();

	// Roue droite
	glPushMatrix();
		GeometricTransform::Translate(-longueur/2, 0, 0);
		DrawRoue();
	glPopMatrix();
}
 
void RenderingGlobalRoutines::DrawCorps(Voiture & scene){

	// Gros bloc
	glPushMatrix();
		GeometricTransform::Scale(1,1,3);
		glutWireCube(10);
	glPopMatrix();

	// Petit bloc
	glPushMatrix();
		GeometricTransform::Translate(0, 8, -3);
		GeometricTransform::Scale(1,1,2);
		glutWireCube(8);
	glPopMatrix();

	// Essieu arriere
	glPushMatrix();
		GeometricTransform::Translate(0, -5, -12);
		DrawEssieu(12);
	glPopMatrix();

	// Essieu avant
	glPushMatrix();
		GeometricTransform::Translate(0, -5, 12);
		DrawEssieu(12);
	glPopMatrix();
}
