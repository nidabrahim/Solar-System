#include "Theiere.h"
#include "RenderingGlobalRoutines.h"


Theiere::Theiere(int size): AbstractScene(), mSize(size){}

Theiere::~Theiere(){}
		
void Theiere::render(){
	
 	RenderingGlobalRoutines::DrawModel(nullptr);
}
