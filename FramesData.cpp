

#include "FramesData.h"
#include "WrapperSDL.h"

// Initialisation des données de classe
uint FramesData::mNbSeconds = 0;
u_int64_t FramesData::mNbFrames=0;
u_int64_t FramesData::mLastNbFrames=0; // compteur de frames
u_int64_t FramesData::mFps = 0; // pour timer affichage
char FramesData::mDescriptionFPS[200];

// Initialisation de la description des FPS
void FramesData::Init() {
	strcpy(mDescriptionFPS, "00 Frames en 00s, FPS: --");
}
	
bool FramesData::Update(){
	mNbFrames++;
	// gestion des frames par secondes (ici 50 fps) 
	u_int32_t currentTime = WrapperSDL::getTicks(); // date courante en milliseconde
	if (currentTime/1000 > mNbSeconds){
		mFps = mNbFrames-mLastNbFrames;
		mLastNbFrames = mNbFrames;
		mNbSeconds++;
		sprintf(mDescriptionFPS, "       %4ld Frames, en %ds, soit %ld FPS       ",
						mNbFrames , mNbSeconds, mFps);
		return true;
	}
	return false;
}

const char* FramesData::getDescriptionFPS(){
    return mDescriptionFPS;
}
