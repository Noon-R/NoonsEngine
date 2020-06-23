#include "ShapeCreator.h"


constexpr Object::Vertex solidCubeVertex[] = {

	{ -1.0f, -1.0f, -1.0f,  -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f, -1.0f,  1.0f,  -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f,  1.0f,  1.0f,  -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f, -1.0f, -1.0f,  -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f,  1.0f,  1.0f,  -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f,  1.0f, -1.0f,  -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},

	{  1.0f, -1.0f, -1.0f,  0.0f, 0.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f, -1.0f, -1.0f,  0.0f, 0.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f,  1.0f, -1.0f,  0.0f, 0.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f, -1.0f, -1.0f,  0.0f, 0.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f,  1.0f, -1.0f,  0.0f, 0.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f,  1.0f, -1.0f,  0.0f, 0.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},

	{ -1.0f, -1.0f, -1.0f,  0.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f, -1.0f, -1.0f,  0.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f, -1.0f,  1.0f,  0.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f, -1.0f, -1.0f,  0.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f, -1.0f,  1.0f,  0.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f, -1.0f,  1.0f,  0.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},

	{  1.0f, -1.0f,  1.0f,  1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f, -1.0f, -1.0f,  1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f,  1.0f, -1.0f,  1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f, -1.0f,  1.0f,  1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f,  1.0f, -1.0f,  1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f,  1.0f,  1.0f,  1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},

	{ -1.0f,  1.0f, -1.0f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f,  1.0f,  1.0f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f,  1.0f,  1.0f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f,  1.0f, -1.0f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f,  1.0f,  1.0f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f,  1.0f, -1.0f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},

	{ -1.0f, -1.0f,  1.0f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f, -1.0f,  1.0f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f,  1.0f,  1.0f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f, -1.0f,  1.0f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{  1.0f,  1.0f,  1.0f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},
	{ -1.0f,  1.0f,  1.0f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f}
};

//constexpr Object::Vertex cubeVertex[] = {
//	{ -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f },  
//	{ -1.0f, -1.0f,  1.0f, 0.0f, 0.0f, 0.8f },     
//	{ -1.0f,  1.0f,  1.0f, 0.0f, 0.8f, 0.0f },   
//	{ -1.0f,  1.0f, -1.0f, 0.0f, 0.8f, 0.8f },  
//	{  1.0f,  1.0f, -1.0f, 0.8f, 0.0f, 0.0f },   
//	{  1.0f, -1.0f, -1.0f, 0.8f, 0.0f, 0.8f },     
//	{  1.0f, -1.0f,  1.0f, 0.8f, 0.8f, 0.0f },     
//	{  1.0f,  1.0f,  1.0f, 0.8f, 0.8f, 0.8f }   
//}; 


////WithIndexVertex
//constexpr Object::Vertex solidCubeVertexNeedIndex[] = {
//
//	{ -1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f, -1.0f,  0.1f,  0.8f, 0.1f},
//
//	{  1.0f, -1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{ -1.0f, -1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{ -1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{  1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//
//	{ -1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.8f},
//	{  1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.8f},
//	{  1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.8f},
//	{ -1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.8f},
//
//	{  1.0f, -1.0f,  1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f, -1.0f, -1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f,  1.0f, -1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f,  1.0f,  1.0f,  0.1f,  0.1f, 0.8f},
//
//	{ -1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.8f,  0.1f, 0.1f},
//	{  1.0f,  1.0f,  1.0f,  0.8f,  0.1f, 0.1f},
//	{  1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.1f},
//
//	{ -1.0f, -1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{  1.0f, -1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{  1.0f,  1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.8f,  0.8f, 0.1f}
//};


////SolidCube
//constexpr Object::Vertex solidCubeVertex[] = {
//
//	{ -1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f, -1.0f,  0.1f,  0.8f, 0.1f},
//
//	{  1.0f, -1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{ -1.0f, -1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{ -1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{  1.0f, -1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{ -1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{  1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//
//	{ -1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.8f},
//	{  1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.8f},
//	{  1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.8f},
//	{ -1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.8f},
//	{  1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.8f},
//	{ -1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.8f},
//
//	{  1.0f, -1.0f,  1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f, -1.0f, -1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f,  1.0f, -1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f, -1.0f,  1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f,  1.0f, -1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f,  1.0f,  1.0f,  0.1f,  0.1f, 0.8f},
//
//	{ -1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.8f,  0.1f, 0.1f},
//	{  1.0f,  1.0f,  1.0f,  0.8f,  0.1f, 0.1f},
//	{ -1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.1f},
//	{  1.0f,  1.0f,  1.0f,  0.8f,  0.1f, 0.1f},
//	{  1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.1f},
//
//	{ -1.0f, -1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{  1.0f, -1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{  1.0f,  1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{ -1.0f, -1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{  1.0f,  1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.8f,  0.8f, 0.1f}
//};


//constexpr GLuint solidCubeIndex[] = {
//	0, 1, 2, 0, 2, 3,
//	0, 3, 4, 0, 4, 5,
//	0, 5, 6, 0, 6, 1,
//	7, 6, 5, 7, 5, 4,
//	7, 4, 3, 7, 3, 2,
//	7, 2, 1, 7, 1, 6
//};


//constexpr GLuint solidCubeIndex[] = {
//	0,  1,  2,  0,  2,  3,
//	4,  5,  6,  4,  6,  7,
//	8,  9, 10,  8, 10, 11,
//   12, 13, 14, 12, 14, 15,
//   16, 17, 18, 16, 18, 19,
//   20, 21, 22, 20, 22, 23
//};


//constexpr GLuint solidCubeIndex[] = {
//	 0,  1,  2,  3,  4,   5,
//	 6,  7,  8,  9, 10,  11,
//	12, 13, 14, 15, 16,  17,
//	18, 19, 20, 21, 22,  23,
//	24, 25, 26, 27, 28,  29,
//	30, 31, 32, 33, 34,  35,
//};

// 六面体の稜線の両端点のインデックス 
constexpr GLuint wireCubeIndex[] = {
	1, 0,
	2, 7,
	3, 0,
	4, 7,
	5, 0,
	6, 7,
	1, 2,
	2, 3,
	3, 4,
	4, 5,
	5, 6,
	6, 1
};

Shape* CreateSolidSphere(AWindowBase* const window, const int slices, const int stacks) {

	std::vector<Object::Vertex> solidSphereVertex;
	float pi = acos(-1);
	for (int j = 0; j <= stacks; ++j) {
		const float t(static_cast<float>(j) / static_cast<float>(stacks));
		const float y(cos(pi * t)), r(sin(pi * t));

		for (int i = 0; i <= slices; i++)
		{
			const float s(static_cast<float>(i) / static_cast<float>(slices));
			const float z(r * cos(2 * pi * s)), x(r * sin(2 * pi * s));

			const Object::Vertex v = { x,y,z,x,y,z , 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f };

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

Shape* CreateSolidCube(AWindowBase* const window)
{
	return new SolidShape(window, 3, 36, solidCubeVertex);
}
