#ifndef HEADER_ABSTRACT_SCENE_HPP
#define HEADER_ABSTRACT_SCENE_HPP

#include "LightSourceData.h"
#include "Material.h"

class AbstractScene{
	
	LightSourceData mlightSources;
	Material mDefaultMaterial;
	
	public:
	
		AbstractScene();
		virtual ~AbstractScene();
		virtual void render() = 0;
		
		const LightSourceData &getLightSources() const;
		const Material &getDefaultMaterial() const;

};

#endif
