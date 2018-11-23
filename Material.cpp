#include "Material.h"

Material::Material( float ambientR, float ambientG , float ambientB , float diffuseR , float diffuseG , float diffuseB , float specularR , float specularG , float specularB , float shininess ) :
				mAmbient{ambientR , ambientG , ambientB , 1.0},
				mDiffuse { diffuseR , diffuseG , diffuseB , 1.0},
				mSpecular{ specularR , specularG , specularB , 1.0},
				mShininess ( shininess )
 {}

 const float * Material::getAmbient() const {
	return mAmbient;
 }

 const float * Material::getDiffuse() const {
	return mDiffuse ;
 }

 const float * Material::getSpecular() const {
	return mSpecular;
 }

 float Material::getShininess() const {
	return mShininess ;
}
