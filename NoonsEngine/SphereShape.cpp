#include "SphereShape.h"

Shape* CreateSolidSphere(WindowBase* const window, const int slices, const int stacks) {

	std::vector<Object::Vertex> solidSphereVertex;
	float pi = acos(-1);
	for (int j = 0; j <= stacks; ++j) {
		const float t(static_cast<float>(j) / static_cast<float>(stacks));
		const float y(cos(pi * t)), r(sin(pi * t));

		for (int i = 0; i <= slices; i++)
		{
			const float s(static_cast<float>(i) / static_cast<float>(slices));
			const float z(r * cos(2 * pi * s)), x(r * sin(2 * pi * s));

			const Object::Vertex v = { x,y,z,x,y,z };

			solidSphereVertex.emplace_back(v);
		}
	}

	std::vector<GLuint> solidSphereIndex;

	for (int j = 0; j < stacks; ++j) {
		const int k((slices + 1) * j);
		for (int i = 0; i < slices; ++i) {
			const GLuint k0(k + i);
			const GLuint k1(k0 + 1);
			const GLuint k2(k1 + slices);
			const GLuint k3(k2 + 1);

			solidSphereIndex.emplace_back(k0);
			solidSphereIndex.emplace_back(k2);
			solidSphereIndex.emplace_back(k3);

			solidSphereIndex.emplace_back(k0);
			solidSphereIndex.emplace_back(k3);
			solidSphereIndex.emplace_back(k1);


		}
	}

	return new SolidShapeIndex(window,
		3,
		static_cast<GLsizei>(solidSphereVertex.size()), solidSphereVertex.data(),
		static_cast<GLsizei>(solidSphereIndex.size()), solidSphereIndex.data()
	);
}
