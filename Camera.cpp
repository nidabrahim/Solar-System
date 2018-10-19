#include <cstring>
#include "Camera.h"
#include "GeometricTransform.h"

Camera::Camera(double angleOuvertureY = 50, double aspect, double z_proche = 1, double z_eloigne = 500 ,
				double positionX, double positionY, double positionZ, 
				double pointDeViseeX, double pointDeViseeY, double pointDeViseeZ, 
				double vecteurVerticalX, double vecteurVerticalY, double vecteurVerticalZ):
				AbstractCamera(angleOuvertureY,aspect,z_proche,z_eloigne,
				positionX, positionY, positionZ, pointDeViseeX, pointDeViseeY, pointDeViseeZ, 
				vecteurVerticalX, vecteurVerticalY, vecteurVerticalZ){}

Camera::~Camera() {}

void Camera::ApplyPerspectiveProjection () const{

	GeometricTransform::ApplyPerspectiveProjection(mAngleOuvertureY, mAspect, mZ_proche, mZ_eloigne);
}

void Camera::n() const{

	GeometricTransform::LookAt(mPosition, mPointDeVisee, mVecteurVertical);
}


