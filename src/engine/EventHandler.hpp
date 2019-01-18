#ifndef __EVENT_HANDLER_H
#define __EVENT_HANDLER_H

#include <SDL2/SDL.h>
#include <boost/function.hpp>
#include <boost/container/map.hpp>


typedef boost::function<void (SDL_Event&)> callback;

/**
 * @brief EventHandler class
 * 
 */
class EventHandler {

	private:
		boost::container::map<SDL_Scancode, bool> keysHeld;
		callback videoResize;
		callback mouseMotion;
		callback quit;
		boost::container::map<SDL_Scancode, callback> keyFunc;
		boost::container::map<SDL_Scancode, callback> keyReleaseFunc;
		boost::container::map<SDL_Scancode, callback> keyFuncOnce;
		static EventHandler *instance;
		
		EventHandler() {};
		EventHandler(EventHandler&) {}
		EventHandler & operator=(EventHandler const&);
		~EventHandler();
		static const unsigned int sdlKeyAmount = 1000;
		void actualHandle(SDL_Event &);
		void handleKeys(SDL_Event &event);
		void cycle();
		void keyDown(SDL_Scancode &, SDL_Event &);
		void keyUp(SDL_Scancode &, SDL_Event &);

	public:
		static EventHandler *inst();
		void handle();
		void registerVideoResizeCallback(callback);
		void registerMouseMotionCallback(callback);
		void registerQuitCallback(callback);
		void registerKey(SDL_Scancode key        , callback);
		void registerKeyOnce(SDL_Scancode key    , callback);
		void registerKeyRelease(SDL_Scancode key , callback);
		void unregisterKey(SDL_Scancode key);
		void unregisterMouseMotion();
};



#endif
