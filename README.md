# Système solaire

Création d’un rendu graphique OpenGL



## Table des matières
* [Dépendances](#dépendances)
* [Prérequis](#prérequis)
* [Installation](#installation)
* [Architecture de code](#architecture-de-code)
* [Réalisations](#réalisations)



## Dépendances

* boost
* OpenGL >= 3.3
* SDL2
* GLU
* GLEW
* SDL2\_image (included)
* [GLM](http://glm.g-truc.net/0.9.4/index.html)
* Scons (for building)



## Prérequis





## Installation

Pour lancer le projet, exécuter sur votre console ces deux commandes :

    scons
	./solarsystem



## Architecture de code

```bash
├── includes
│   ├── shaders
│   │   ├── earth.frag
│   │   ├── earth.vert
│   │   ├── moon.frag
│   │   ├── moon.vert
│   │   ├── skybox.frag
│   │   ├── skybox.vert
│   │   ├── sun.frag
│   │   └── sun.vert
│   └── textures
│       ├── earth
│       │   ├── morning
│       │   │   ├── earth_xn.png
│       │   │   ├── earth_xp.png
│       │   │   ├── earth_yn.png
│       │   │   ├── earth_yp.png
│       │   │   ├── earth_zn.png
│       │   │   └── earth_zp.png
│       │   └── night
│       │       ├── earth_xn.png
│       │       ├── earth_xp.png
│       │       ├── earth_yn.png
│       │       ├── earth_yp.png
│       │       ├── earth_zn.png
│       │       └── earth_zp.png
│       ├── moon
│       │   ├── moon_xn.png
│       │   ├── moon_xp.png
│       │   ├── moon_yn.png
│       │   ├── moon_yp.png
│       │   ├── moon_zn.png
│       │   └── moon_zp.png
│       ├── skybox
│       │   ├── skybox_xn.png
│       │   ├── skybox_xp.png
│       │   ├── skybox_yn.png
│       │   ├── skybox_yp.png
│       │   ├── skybox_zn.png
│       │   └── skybox_zp.png
│       └── sun
│           └── sun_colors.png
├── SConstruct
├── src
│   ├── engine
│   │   ├── camera.cpp
│   │   ├── camera.hpp
│   │   ├── Engine.cpp
│   │   ├── Engine.hpp
│   │   ├── EventHandler.cpp
│   │   ├── EventHandler.hpp
│   │   ├── glmUtils.cpp
│   │   ├── glmUtils.hpp
│   │   ├── shader.cpp
│   │   ├── shader.hpp
│   │   ├── shader_object.cpp
│   │   ├── shader_object.hpp
│   │   ├── texture_object.cpp
│   │   └── texture_object.hpp
│   ├── geometry
│   │   ├── cube.cpp
│   │   ├── cube.hpp
│   │   ├── sphere.cpp
│   │   └── sphere.hpp
│   ├── main.cpp
│   ├── models
│   │   ├── earth.cpp
│   │   ├── earth.hpp
│   │   ├── moon.cpp
│   │   ├── moon.hpp
│   │   ├── skybox.cpp
│   │   ├── skybox.hpp
│   │   ├── sun.cpp
│   │   └── sun.hpp
│   ├── SConstruct
│   ├── solar_system.cpp
│   ├── solar_system_globals.hpp
│   └── solar_system.hpp
└── UML
    └── ClassDiagram.pdf

```



## Réalisations

* Programmation par Shaders et VBO
* Shadow Mapping
* Application de textures sur les Objets 3d
* Affichage d’une scène 3D contenant plusieurs objets
* Déplacement de la caméra dans la scène
* Eclairage Ambiant
* Eclairage spéculaire sur certains objets
* Skyboxes



