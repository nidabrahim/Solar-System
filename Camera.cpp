#include <cstring>
#include "Camera.h"
#include "GeometricTransform.h"

Camera::Camera(double angleOuvertureY, double aspect, double z_proche, double z_eloigne,
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

void Camera::ApplyCameraCoordinates() const{

	GeometricTransform::LookAt(mPosition, mPointDeVisee, mVecteurVertical);
}

void Camera::UpdateAngle(double angleOuvertureY){
	
	this->mAngleOuvertureY = angleOuvertureY;
	this->ApplyPerspectiveProjection();
}

