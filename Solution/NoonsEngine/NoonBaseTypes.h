#pragma once
#include "CONFIG.h"

#ifdef DEBUG_NOONENGINE

#ifndef ENGINE_DEBUG
#define ENGINE_DEBUG 1

typedef float Nfloat;
typedef int   Nint;
typedef unsigned int  Nuint;

#endif // !


#endif // DEBUG


#ifdef NOON_TYPES_OPENGL

#include<GLFW/glfw3.h>
#include <GL/glew.h>

typedef GLfloat Nfloat;
typedef GLint   Nint;
typedef GLuint  Nuint;

#endif

#ifdef NOON_TYPES_DIRECTX

#endif