#ifndef HEADER_MATERIAL_H
#define HEADER_MATERIAL_H

#include <cstdlib>

class Material {
	float mAmbient[4]; // C o e f f i c i e n t de r é f l e x i o n ambiante
	float mDiffuse[4]; // C o e f f i c i e n t de r é f l e x i o n d i f f u s e
	float mSpecular[4]; // C o e f f i c i e n t de r é f l e x i o n sp é c u l a i r e
	float mShininess;  // B r i l l a n c e

	public :

	 Material ( float ambientR , float ambientG , float ambientB , float diffuseR , float diffuseG , float diffuseB ,float specularR , float specularG , float specularB , float shininess ) ;

	 const float *getAmbient ( ) const ;

	 const float * getDiffuse( ) const ;

	 const float * getSpecular ( ) const ;

	 float getShininess() const ;
};
#endif
