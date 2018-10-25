

#include "MainApplication.h"

MainApplication::MainApplication(int largeurFenetreInit, int hauteurFenetreInit,
                                 const char *windowTitle, int argc,
                                 char **argv) :
        mWrapperSDL(largeurFenetreInit, hauteurFenetreInit,
                    windowTitle, argc, argv),
        mModele(largeurFenetreInit, hauteurFenetreInit)
{}
