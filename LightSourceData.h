#ifndef HEADER_LIGHTSOURCE_DATA_H
#define HEADER_LIGHTSOURCE_DATA_H

#include <vector>
#include "RenderingGlobalRoutines.h"


class LightSourceData {
 public :
 /** Classe repr é sentant une source lumineuse */
 class PointLightSource {
	int mLightId ;
	public :
		int getLightId ( ) const ;

		const float * getLightPosition ( ) const ;

		const float * getDiffuseIntensity ( ) const ;
	
		const float * getSpecularIntensity ( ) const ;

	private :

		float mLightPosition [ 4 ] = {0.0f , 0.0f , 10.0f , 0.0f } ;
		float mDiffuseIntensity [ 4 ] = {0.6f , 0.6f , 0.6f , 1.0f } ; // I n t e n s i t é d i f f u s e
		float mSpecularIntensity [ 4 ] = {0.6f , 0.6f , 0.6f , 1.0f } ; // I n t e n s i t é sp é c u l a i r e

	public :
 
		PointLightSource ( int lightId ,float lightPositionX ,float lightPositionY ,float lightPositionZ,float diffuseIntensityR ,float diffuseIntensityG , float diffuseIntensityB ,float specularIntensityR , float specularIntensityG , float specularIntensityB ) ;

		 /** Positionner l a source dans l e repère courant */
		 void ApplyPosition ( ) const ;

		 /** Applique l ’ i n t e n s i t é de l a source et a c t i v e l a source */
		 void ApplyIntensity ( ) const ;

		 /** Dé s a c t i v e l a source */
		 void Disable ( ) const ;
 };

 /** Types de repères support é s ( repères du monde et de l a camé ra ) */
 enum class TypeRepere{
	MONDE = 0 , CAMERA = 1
 };

 /** Constructeur par dé f a u t ( ne cr é e aucune source lumineuse ) */
 LightSourceData ( ) ;

 /** Destructeur */
 ~LightSourceData ( ) = default ;

/** Ajoute une source lumineuse dans un c e r t a i n repère
* @return true en case de succès , f a l s e en cas d ’ID l i g h t I d dé j à p r i s */
 bool AddSource ( LightSourceData::TypeRepere typeRepere , int lightId ,
 float lightPositionX , float lightPositionY , float lightPositionZ ,
 float diffuseIntensityR , float diffuseIntensityG , float diffuseIntensityB ,
 float specularIntensityR , float specularIntensityG , float specularIntensityB
) ;

 /** Supprime une source lumineuse dans un c e r t a i n repère
 * La mé thode e s t un peu lourde pour garder des t a b l e a u x contigus .
 * @return true en case de succès , f a l s e en case d ’ID i n e x i s t a n t */
 bool DeleteSource ( int lightId);

 /** Positionner l e s sources qui se trouvent dans un c e r t a i n repère */
 void ApplyLightPositions ( LightSourceData::TypeRepere typeRepere ) const ;


 void ApplyLightIntensities ( ) const ;


 void DisableLightSources ( LightSourceData::TypeRepere typeRepere ) ;

 private :

 std::vector<LightSourceData::PointLightSource>& GetSourcesByRepere (LightSourceData::TypeRepere typeRepere , bool reverse = false ) ;
 const std::vector<LightSourceData::PointLightSource>& GetSourcesByRepere (LightSourceData::TypeRepere typeRepere , bool reverse = false ) const ;

 /** C o l l e c t i o n de sources lumineuses dans l e repère de l a camé ra */
 std::vector<PointLightSource> mSourcesRepereCamera ;
 /** C o l l e c t i o n de sources lumineuses dans l e repère du monde */
 std::vector<PointLightSource> mSourcesRepereMonde ;
 
 };
 #endif
