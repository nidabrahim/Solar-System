#include <cstring>
#include "abstractCamera.h"
#include "GeometricTransform.h"


AbstractCamera::AbstractCamera(double angleOuvertureY, double aspect, double z_proche, double z_eloigne,
							double positionX ,double positionY ,double positionZ ,
							double pointDeViseeX , double pointDeViseeY , double pointDeViseeZ ,
							double vecteurVerticalX ,double vecteurVerticalY , double vecteurVerticalZ):
							mAngleOuvertureY(angleOuvertureY), mAspect(aspect), mZ_proche(z_proche), mZ_eloigne(z_eloigne) 
{
	this->mPosition[0] = positionX ;
	this->mPosition[1] = positionY ;
	this->mPosition[2] = positionZ ;
	this->mPointDeVisee[0] = pointDeViseeX ;
	this->mPointDeVisee[1] = pointDeViseeY ;
	this->mPointDeVisee[2] = pointDeViseeZ ;
	this->mVecteurVertical[0] = vecteurVerticalX ;
	this->mVecteurVertical[1] = vecteurVerticalY ;
	this->mVecteurVertical[2] = vecteurVerticalZ ;
}

AbstractCamera::~AbstractCamera() {

}

void AbstractCamera::SetProjection(double angleOuvertureY ,double aspect ,double z_proche ,double z_eloigne ){
	this->mAngleOuvertureY = angleOuvertureY ;
	this->mAspect = aspect ;
	this->mZ_proche = z_proche ;
	this->mZ_eloigne = z_eloigne ;
}

void AbstractCamera::UpdateAspect(double aspect){

	SetProjection(this->mAngleOuvertureY, aspect, this->mZ_proche, this->mZ_eloigne);
}

void AbstractCamera::ClearModelView(){

	GeometricTransform::ClearModelView();
}

void AbstractCamera::ClearProjection(){

	GeometricTransform::ClearProjection();
}

void AbstractCamera::LookAt(double position[3], double pointDeVisee[3], double vecteurVertical[3]){
	
	memcpy(mPosition, position, 3 *sizeof(double));
	memcpy(mPointDeVisee, pointDeVisee,  3 *sizeof(double));
	memcpy(mVecteurVertical, vecteurVertical, 3 *sizeof(double));
}

/*

void AbstractCamera::Redimensionnement(int l, int h) {
	this->mAspect = (double)l/(double)h;
    this->ApplyPerspectiveProjection();
}

void AbstractCamera::ChangementAngle(double angleOuvertureY){
	this->mAngleOuverture = angleOuvertureY;
	this->ApplyPerspectiveProjection();
}
*/
void AbstractCamera::Zoom(bool forward) {
	int i;
	if(forward) {
		for(i=0;i<3;i++) {
			this->mPosition[i] = this->mPointDeVisee[i] + 1.1 * (this->mPosition[i] - this->mPointDeVisee[i]);
		}
	} else {
		for(i=0;i<3;i++) {
			this->mPosition[i] = ((this->mPosition[i] - this->mPointDeVisee[i]) / 1.1) + this->mPointDeVisee[i];
		}
	}
}

/**
 * GETTERS
 */
double AbstractCamera::GetAngleOuvertureY() {
	return this->mAngleOuvertureY;
}

double* AbstractCamera::GetPosition() {
	return this->mPosition;
}

double* AbstractCamera::GetPointDeVisee() {
	return this->mPointDeVisee;
}

double* AbstractCamera::GetVecteurVertical() {
	return this->mVecteurVertical;
}

/**
 * SETTERS
 */
void AbstractCamera::SetAngleOuvertureY(double ae) {
	this->mAngleOuvertureY = ae;
}

void AbstractCamera::SetPostion(double px,  double py, double pz) {
	this->mPosition[0] = px;
	this->mPosition[1] = py;
	this->mPosition[2] = pz;
}

void AbstractCamera::SetPointDeVisee(double vx, double vy, double vz) {
	this->mPointDeVisee[0] = vx;
	this->mPointDeVisee[1] = vy;
	this->mPointDeVisee[2] = vz;
}

void AbstractCamera::SetVecteurVertical(double vertx, double verty, double vertz) {
	this->mVecteurVertical[0] = vertx;
	this->mVecteurVertical[1] = verty;
	this->mVecteurVertical[2] = vertz;
}
