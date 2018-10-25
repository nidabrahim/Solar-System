#ifndef HEADER_THEIERE_HPP
#define HEADER_THEIERE_HPP

#include "AbstractScene.h"

class Theiere : public AbstractScene {

	private:
		int mSize;
	
	public:
		Theiere(int size = 3);
		~Theiere();
		void render();

};

#endif
