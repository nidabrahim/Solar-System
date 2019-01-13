#include "EventHandler.hpp"
#include <utility>
#include <boost/foreach.hpp>

EventHandler * EventHandler::instance = NULL;

EventHandler * EventHandler::inst() {
	if (!instance) {
		instance = new EventHandler;
	}

	return instance;
}

#include <iostream>
using namespace std;

/**
 * Handle the events
 */
void EventHandler::handle() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
					if (videoResize) {
						videoResize(event);
					}
				}
				break;
			case SDL_QUIT:
				quit(event);
				break;
			case SDL_KEYDOWN:
				keyDown(event.key.keysym.scancode, event);
				keysHeld[event.key.keysym.scancode] = true;
				break;
			case SDL_KEYUP:
				keyUp(event.key.keysym.scancode, event);
				keysHeld[event.key.keysym.scancode] = false;
				break;
			case SDL_MOUSEMOTION:
				if (mouseMotion) {
					mouseMotion(event);
				}
				break;
		}
	}

	cycle();
}

void EventHandler::registerMouseMotionCallback(callback func) {
	this->mouseMotion = func;
}

void EventHandler::unregisterMouseMotion() {
	this->mouseMotion = NULL;
}

/**
 * Register the function for the video resize
 */
void EventHandler::registerVideoResizeCallback(callback func) {
	videoResize = func;
}

void EventHandler::registerQuitCallback(callback func) {
	quit = func;
}

/**
 * Trigger the func on a key once
 */
void EventHandler::keyDown(SDL_Scancode &key, SDL_Event &event) {
	if (keysHeld.find(key) != keysHeld.end()) {
		if (!keysHeld[key]) {
			if (keyFuncOnce[key]) {
				keyFuncOnce[key](event);
			}
		}
	}

	if (keyFunc[key]) {
		keyFunc[key](event);
	}
}

/**
 * When a key is released, call the release function
 */
void EventHandler::keyUp(SDL_Scancode &key, SDL_Event &event) {
	if (keyReleaseFunc[key]) {
		keyReleaseFunc[key](event);
	}
}

/**
 * When a key is held, call the associated function (if set)
 */
void EventHandler::cycle() {
	std::pair<SDL_Scancode, bool> i;

	
	// BOOST_FOREACH(i, keysHeld) {
	// 	if (i.second) {
	// 		cout << "Key press of " << i.first << endl;
	// 		keyFunc[i.first](event);
	// 	}
	// }
	

	
	// for (unsigned int i = 0; i < sdlKeyAmount; i++) {
	// 	if (keysHeld[i]) {
	// 		if (keyFunc[i]) {
	// 			keyFunc[i](event);
	// 		}
	// 	}
	// }
	
}



/**
 * Register a key to the list
 */
void EventHandler::registerKey(SDL_Scancode key, callback func) {
	keyFunc[key] = func;
}

/**
 * Register function to a key when it's released
 */
void EventHandler::registerKeyRelease(SDL_Scancode key, callback func) {
	keyReleaseFunc[key] = func;
}

/**
 * Register a function to be spawned only once when pressing the key
 */
void EventHandler::registerKeyOnce(SDL_Scancode key, callback func) {
	keyFuncOnce[key] = func;
}

/**
 * Unregister the function on a key
 *
 * For now unregister all the possible variations
 * of the callbacks.
 */
void EventHandler::unregisterKey(SDL_Scancode key) {
	keyFunc[key]        = NULL;
	keyReleaseFunc[key] = NULL;
	keyFuncOnce[key]    = NULL;
}
