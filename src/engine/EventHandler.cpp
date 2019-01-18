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
 * @brief Handle the events
 * 
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

/**
 * @brief Register the function for the mouse motion
 * 
 * @param func 
 */
void EventHandler::registerMouseMotionCallback(callback func) {
	this->mouseMotion = func;
}

/**
 * @brief Unregister the function for the mouse motion
 * 
 */
void EventHandler::unregisterMouseMotion() {
	this->mouseMotion = NULL;
}

/**
 * @brief Register the function for the video resize
 * 
 */
void EventHandler::registerVideoResizeCallback(callback func) {
	videoResize = func;
}

/**
 * @brief Register the function for the quit event
 * 
 * @param func 
 */
void EventHandler::registerQuitCallback(callback func) {
	quit = func;
}

/**
 * @brief Trigger the function on a key once
 * 
 * @param key 
 * @param event 
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
 * @brief When a key is released, call the release function
 * 
 * @param key 
 * @param event 
 */
void EventHandler::keyUp(SDL_Scancode &key, SDL_Event &event) {
	if (keyReleaseFunc[key]) {
		keyReleaseFunc[key](event);
	}
}

/**
 * @brief When a key is held, call the associated function if set
 * 
 */
void EventHandler::cycle() {
	std::pair<SDL_Scancode, bool> i;	
}


/**
 * @brief Register a key to the list
 * 
 * @param key 
 * @param func 
 */
void EventHandler::registerKey(SDL_Scancode key, callback func) {
	keyFunc[key] = func;
}

/**
 * @brief Register a function to a key when it's released
 * 
 * @param key 
 * @param func 
 */
void EventHandler::registerKeyRelease(SDL_Scancode key, callback func) {
	keyReleaseFunc[key] = func;
}

/**
 * @brief Register a function to be spawned only once when pressing the key
 * 
 * @param key 
 * @param func 
 */
void EventHandler::registerKeyOnce(SDL_Scancode key, callback func) {
	keyFuncOnce[key] = func;
}

/**
 * @brief Unregister the function on a key
 * 
 * @param key 
 */
void EventHandler::unregisterKey(SDL_Scancode key) {
	keyFunc[key]        = NULL;
	keyReleaseFunc[key] = NULL;
	keyFuncOnce[key]    = NULL;
}
