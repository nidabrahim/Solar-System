CXXFLAGS =  -std=c++11 -Wall -pedantic \
    -pedantic-errors -Wextra -Wcast-align \
    -Wcast-qual  -Wchar-subscripts  -Wcomment -Wconversion \
    -Wdisabled-optimization \
    -Werror -Wformat -Wformat=2 \
    -Wformat-nonliteral -Wformat-security  \
    -Wformat-y2k \
    -Wimport  -Winit-self  -Winline \
    -Winvalid-pch   \
    -Wunsafe-loop-optimizations -Wmissing-braces \
    -Wmissing-field-initializers -Wmissing-format-attribute   \
    -Wmissing-include-dirs -Wmissing-noreturn \
    -Wparentheses  -Wpointer-arith \
    -Wredundant-decls -Wreturn-type \
    -Wsequence-point  -Wshadow -Wsign-compare  -Wstack-protector \
    -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch  -Wswitch-default \
    -Wswitch-enum -Wtrigraphs  -Wuninitialized \
    -Wunknown-pragmas  -Wunreachable-code -Wunused \
    -Wunused-function  -Wunused-label  -Wunused-parameter \
    -Wunused-value  -Wunused-variable  -Wvariadic-macros \
    -Wvolatile-register-var  -Wwrite-strings -Wfloat-equal \
    -Weffc++


all: run

run: main.cpp DisplayManager.cpp EventController.cpp FramesData.cpp  Modele.cpp\
         WrapperSDL.cpp MouseData.cpp MainApplication.cpp WindowManager.cpp\
         abstractCamera.cpp Camera.cpp GeometricTransform.cpp RenderingGlobalRoutines.cpp AbstractScene.cpp Theiere.cpp SystemeSolaire.cpp\
	 DisplayManager.h FramesData.h  Modele.h\
         WrapperSDL.h MouseData.h MainApplication.h\
         abstractCamera.h Camera.h GeometricTransform.h RenderingGlobalRoutines.h AbstractScene.h Theiere.h SystemeSolaire.h\

	g++ $(CXXFLAGS) main.cpp DisplayManager.cpp EventController.cpp FramesData.cpp  Modele.cpp\
         WrapperSDL.cpp MouseData.cpp MainApplication.cpp WindowManager.cpp\
         abstractCamera.cpp Camera.cpp GeometricTransform.cpp RenderingGlobalRoutines.cpp AbstractScene.cpp Theiere.cpp SystemeSolaire.cpp\
				 -o run -lSDL2 -lGL -lGLU  -lSDL2_ttf -lglut
clean:
	rm -f run
