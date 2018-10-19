#include <GLES3/gl3.h>
#include <GL/glut.h>
#include "GeometricTransform.h"

void GeometricTransform::Viewport(int32_t viewCenterX ,int32_t viewCenterY,u_int32_t viewWidth ,  u_int32_t  viewHeight ) {
	glViewport(viewCenterX , viewCenterY , viewWidth , viewHeight ) ;
}

void GeometricTransform::ApplyPerspectiveProjection(double angleOuvertureY,double aspect,double zProche,double zEloigne ) {

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angleOuvertureY,aspect,zProche,zEloigne);
}

void GeometricTransform::ClearModelView () {

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GeometricTransform::ClearProjection () {

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void GeometricTransform::LookAt(const double position[3],const double pointDeVisee[3],const double vecteurVertical[3]) {

	gluLookAt(position[0],position[1],position[2],pointDeVisee[0],pointDeVisee[1],pointDeVisee[2],vecteurVertical[0],vecteurVertical[1],vecteurVertical[2]);
}

void GeometricTransform::Translate(double vecX ,double vecY ,double vecZ ) {

	glTranslated(vecX,vecY,vecZ);
}

void GeometricTransform::Rotate(double vecX,double vecY,double vecZ,double angle){

	glRotated(vecX,vecY,vecZ,angle) ;
}

void GeometricTransform::Scale(double factorX ,double factorY ,double factorZ ) {

	glScaled(factorX,factorY,factorZ );
}
