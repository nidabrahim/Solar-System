#ifndef HEADER_ABSTRACT_SCENE_HPP
#define HEADER_ABSTRACT_SCENE_HPP


class AbstractScene{
	
	
	public:
	
		AbstractScene();
		virtual ~AbstractScene();
		virtual void render() = 0;

};

#endif
