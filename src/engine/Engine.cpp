#include "Engine.hpp"

#include <iostream>
#include <boost/bind.hpp>
#include <GL/glu.h>
#include <SDL2/SDL.h>

#include "camera.hpp"
#include "EventHandler.hpp"

/**
 * @brief Construct a new Engine:: Engine object
 * 
 * @param name 
 * @param scrW 
 * @param scrH 
 * @param flags 
 * @param argc 
 * @param argv 
 */
Engine::Engine(string name, GLuint scrW, GLuint scrH, int flags, int argc, char**argv) :
	scrW(scrW),
	scrH(scrH),
	running(false),
	flags(flags)
{
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

	initSDL(name);
	initOpenGL();

    //! Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
    }
    //! Use Vsync
    if( SDL_GL_SetSwapInterval( 1 ) < 0 )
    {
        printf( "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
    }
    //! Set screen weight and height
    Camera::inst()->setRes(scrW, scrH);

	initEvents();
}

/**
 * @brief 
 * 
 * @param renderFunc 
 */
void Engine::registerRenderFunc(render_func renderFunc) {
	this->renderFunc = renderFunc;
}

/**
 * @brief Render function
 * 
 */
void Engine::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	GLuint currentTime = SDL_GetTicks();

	EventHandler::inst()->handle();
	renderFunc(currentTime, *this);

	if (flags & engineFlags::SHOW_FPS) {
		fps(currentTime);
	}

	handleErrors();

	SDL_GL_SwapWindow(window);
}

void Engine::fps(GLuint time) {
	frameCounter++;

	timer += time - lastDraw;

	if (timer > 1000) {
		cout << frameCounter << " frames per second" << endl;
		timer = 0;
		frameCounter = 0;
	}
	lastDraw = time;
}

/**
 * @brief Engine runner
 * 
 */
void Engine::run() {
	running = true;

	while (running) {
		render();
	}

	// cleanup
	SDL_Quit();
}

/**
 * @brief Initialize SDL
 * 
 * @param name 
 */
void Engine::initSDL(string name) {

	SDL_Init(SDL_INIT_EVENTS);

	int sdlFlags = SDL_WINDOW_OPENGL;
	if (flags & RUN_FULLSCREEN) {
		SDL_DisplayMode mode;
		SDL_GetCurrentDisplayMode(0, &mode);

		scrW = mode.w;
		scrH = mode.h;

		sdlFlags = sdlFlags | SDL_WINDOW_FULLSCREEN;
	}
	else {
		sdlFlags = sdlFlags | SDL_WINDOW_RESIZABLE;
	}

	window = SDL_CreateWindow(
			name.c_str(), 
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			scrW,
			scrH,
			sdlFlags
	);

	context = SDL_GL_CreateContext(window);
	atexit(SDL_Quit);
}


/**
 * @brief Initialize OpenGL
 * 
 */
void Engine::initOpenGL() {
	if (flags & PRINT_VERSION) {
		cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
		cout << "Vendor: " << glGetString(GL_VENDOR) << endl;
		cout << "Version: " << glGetString(GL_VERSION) << endl;
		cout << "Shader: " << glGetString(GL_SHADING_LANGUAGE_VERSION)<< endl;
	}

	glShadeModel(GL_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
}

/**
 * @brief Initialize Events
 * 
 */
void Engine::initEvents() {
	EventHandler::inst()->registerVideoResizeCallback (boost::bind(&Engine::videoResize, this, _1));
	EventHandler::inst()->registerQuitCallback        (boost::bind(&Engine::quit, this, _1));

	EventHandler::inst()->registerKey(SDL_SCANCODE_ESCAPE, boost::bind(&Engine::quit, this, _1));
}

/**
 * @brief Resize event
 * 
 * @param event 
 */
void Engine::videoResize(SDL_Event &event) {
	scrW = event.window.data1;
	scrH = event.window.data2;

	Camera::inst()->setRes(scrW, scrH);
}

/**
 * @brief Quit event
 * 
 * @param event 
 */
void Engine::quit(SDL_Event &event) {
	running = false;
}

/**
 * @brief Handle errors
 * 
 */
void Engine::handleErrors() {
	GLenum errCode;
	const GLubyte *errString;
	while ((errCode = glGetError()) != GL_NO_ERROR) {
		errString = gluErrorString(errCode);
		cerr << "OpenGL Error: " << errString << endl;
	}
}

