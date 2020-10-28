#pragma once

#ifdef DEBUG_NOONENGINE

#ifndef ENGINE_DEBUG
#define ENGINE_DEBUG 1

typedef float Nfloat;
typedef int   Nint;
typedef unsigned int  Nuint;

#endif // !


#endif // DEBUG


#ifndef NOON_TYPES_OPENGL
#define NOON_TYPES_OPENGL 1

#include <GL/glew.h>

typedef GLfloat Nfloat;
typedef GLint   Nint;
typedef GLuint  Nuint;

#endif

#ifndef NOON_TYPES_DIRECTX
#define NOON_TYPES_DIRECTX 1

#endif