#pragma once
#include <GL/GL.h>

namespace Noon {
	namespace GraphicsCore {
		struct Vertex {
			GLfloat position[3];
			GLfloat normal[3];
			GLfloat color[4];
			GLfloat uv[2];
		};
	}
}