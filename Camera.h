#ifndef HEADER_CAMERA_H
#define HEADER_CAMERA_H

#include "abstractCamera.h"

class Camera : public AbstractCamera {


	public:

		Camera(double angleOuvertureY = 50, double aspect= 0, double z_proche = 1, double z_eloigne = 500 ,
				double positionX= 0, double positionY= 0, double positionZ= 0, 
				double pointDeViseeX= 0, double pointDeViseeY= 0, double pointDeViseeZ= 0, 
				double vecteurVerticalX= 0, double vecteurVerticalY= 0, double vecteurVerticalZ= 0);
				
		virtual ~Camera();

		virtual void ApplyPerspectiveProjection() const;
		
		virtual void ApplyCameraCoordinates() const;
		
		void UpdateAngle(double angleOuvertureY);
  
};

#endif
