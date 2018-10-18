
#ifndef HEADER_GEOMETRIC_TRANSFORM_H
#define HEADER_GEOMETRIC_TRANSFORM_H

#include <cstdlib>

struct GeometricTransform{
	
	static void Viewport(int32_t viewCenterX ,int32_t  viewCenterY ,u_int32_t viewWidth ,  u_int32_t  viewHeight );
	
	static void ApplyPerspectiveProjection (double angleOuvertureY,double aspect,double zProche,double zEloigne);
	
	static void ClearModelView () ;
	
	static void ClearProjection () ;
	
	static void LookAt(const double position [ 3 ] ,const double pointDeVisee [ 3 ] ,const double vecteurVertical [ 3 ] ) ;
	
	static void Translate (double vecX ,double vecY ,double vecZ ) ;
	
	static void Rotate (double vecX ,double vecY , double vecZ ,double angle ) ;
	
	static void Scale (double factorX ,double factorY ,double factorZ ) ;

} ;

#endif


