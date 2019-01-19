 
# Project #-----------------------------------------------------------------------------------------
project ( solar_system )

cmake_minimum_required ( VERSION 2.8.9 )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/lib/")

find_package( Boost COMPONENTS system filesystem REQUIRED )
find_package ( OpenGL REQUIRED )
find_package ( SDL2 REQUIRED )
find_package ( SDL2_image REQUIRED )
find_package ( GLEW )


# C++ Warning Level #-------------------------------------------------------------------------------
if ( CMAKE_COMPILER_IS_GNUCXX )
 set ( CMAKE_CXX_FLAGS "-Wall -pedantic ${CMAKE_CXX_FLAGS}" )
endif()

# C++11 #-------------------------------------------------------------------------------------------
include ( CheckCXXCompilerFlag )

check_cxx_compiler_flag ( "-std=gnu++14" COMPILER_SUPPORTS_CPP14 )
check_cxx_compiler_flag ( "-std=gnu++1y" COMPILER_SUPPORTS_CPP1Y )
check_cxx_compiler_flag ( "-std=gnu++11" COMPILER_SUPPORTS_CPP11 )
check_cxx_compiler_flag ( "-std=gnu++0x" COMPILER_SUPPORTS_CPP0X )

if ( COMPILER_SUPPORTS_CPP14 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++14 ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP1Y )
 set ( CMAKE_CXX_FLAGS "-std=gnu++1y ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP11 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}" )
elseif( COMPILER_SUPPORTS_CPP0X )
 set ( CMAKE_CXX_FLAGS "-std=gnu++0x ${CMAKE_CXX_FLAGS}" )
else ()
 message ( STATUS "Compiler ${CMAKE_CXX_COMPILER} has no C++11/14 support." )
endif ()

message ( STATUS "Compiler flags: ${CMAKE_CXX_FLAGS}" )

# Sources #-----------------------------------------------------------------------------------------
set ( HEADERS
      src/solar_system_globals.hpp
      src/solar_system.hpp
      src/engine/camera.hpp
      src/engine/Engine.hpp
      src/engine/EventHandler.hpp
      src/engine/glmUtils.hpp
      src/engine/shader_object.hpp
      src/engine/texture_object.hpp
      src/engine/shader.hpp
      src/geometry/sphere.hpp
	  src/geometry/cube.hpp
	  src/models/earth.hpp
      src/models/moon.hpp
	  src/models/skybox.hpp
      src/models/sun.hpp
    )

set ( SOURCES
      src/main.cpp
      src/solar_system.cpp
      src/engine/camera.cpp
      src/engine/Engine.cpp
      src/engine/EventHandler.cpp
      src/engine/glmUtils.cpp
      src/engine/shader_object.cpp
      src/engine/texture_object.cpp
      src/engine/shader.cpp
      src/geometry/sphere.cpp
	  src/geometry/cube.cpp
	  src/models/earth.cpp
      src/models/moon.cpp
	  src/models/skybox.cpp
      src/models/sun.cpp
	  
    )


include_directories( src/ ${OPENGL_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} )

# Executables #-------------------------------------------------------------------------------------
add_executable ( ${CMAKE_PROJECT_NAME}
                 ${HEADERS}
                 ${SOURCES}
               )

# Build #-------------------------------------------------------------------------------------------
set_target_properties ( ${CMAKE_PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C )
target_link_libraries ( ${CMAKE_PROJECT_NAME} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} ${OPENGL_glu_LIBRARY} ${GLEW_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} )

