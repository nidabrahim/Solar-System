#include "AbstractScene.h"

AbstractScene::AbstractScene():
				mlightSources(),
				mDefaultMaterial (0.2f, 0.2f, 0.2f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 110.0f) 
{
	if( !mlightSources.AddSource(
				LightSourceData::TypeRepere::MONDE,
				GL_LIGHT0,
				0.0f,0.0f,10.0f,
				0.6f,0.6f,0.6f,
				0.6f,0.6f,0.6f ))
	{
		fprintf( stderr ," Impossible d’ajouter la source lumineuse.\n");
	}
}

AbstractScene::~AbstractScene(){}

const LightSourceData &AbstractScene::getLightSources() const
{
	return mlightSources;
}

const Material &AbstractScene::getDefaultMaterial() const
{
	return mDefaultMaterial;
}

