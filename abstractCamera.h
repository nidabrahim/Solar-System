#ifndef HEADER_ABSTRACT_CAMERA_HPP
#define HEADER_ABSTRACT_CAMERA_HPP


class AbstractCamera {

	protected:
	
		double mAngleOuvertureY ;
		double mAspect;
		double mZ_proche ;
		double mZ_eloigne ;
		double mPosition[3];
		double mPointDeVisee[3];
		double mVecteurVertical[3];

	public:

		AbstractCamera(double angleOuvertureY = 50, double aspect= 0, double z_proche = 1, double z_eloigne = 500,
					double positionX= 0 ,double positionY= 0 ,double positionZ= 0 ,
					double pointDeViseeX= 0 , double pointDeViseeY= 0 , double pointDeViseeZ= 0 ,
					double vecteurVerticalX= 0 ,double vecteurVerticalY= 0 , double vecteurVerticalZ= 0);
					
		virtual ~AbstractCamera();

		void SetProjection(double angleOuvertureY,double aspect,double z_proche,double z_eloigne);
		
		void UpdateAspect(double aspect ) ;
		
		static void ClearModelView() ;
		
		static void ClearProjection () ;

		void LookAt(double position[3], double pointDeVisee[3], double vecteurVertical[3]);
		
		virtual void ApplyPerspectiveProjection() const;
		
		virtual void ApplyCameraCoordinates() const;

		/*
		void Redimensionnement(int w, int h);
		void ChangementAngle(double angleOuvertureY);
		void Zoumage(bool forward);
		*/
		  

		/**
		 * GETTERS
		 */
		double GetAngleOuvertureY();
		
		double* GetPosition();

		double* GetPointDeVisee();

		double* GetVecteurVertical();
		
		/**
		 * SETTERS
		 */
		void SetAngleOuvertureY(double ao);
		
		void SetPostion(double px,  double py, double pz);

		void SetPointDeVisee(double vx, double vy, double vz);

		void SetVecteurVertical(double vertx, double verty, double vertz);
};


#endif
