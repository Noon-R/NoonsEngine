#include "ModelLoader.h"


Object::Vertex* LoadObjFile(char const* name)
{
	std::vector<Object::Vertex> vertecies;
	std::vector<float[3]> poses;
	std::vector<float[3]> normals;
	std::vector<float[2]> uvs;

	std::string filePath = "./Models/" + std::string(name);

	std::ifstream objFIle(filePath,std::ios::in);
	std::string line;

	std::cout << filePath << std::endl;


	if (objFIle.fail()) {
		std::cout << "Could not Find File or Read File" << std::endl;
		return nullptr;
	}

	while (std::getline(objFIle,line)) {

		std::stringstream ss;
		std::string top;

		ss >> top;

		if (top == "v") {
			float pos[3];

			ss >> pos[0] >> pos[1] >> pos[2];

			poses.push_back(pos);
		}else if (top == "vn") {
			float nor[3];

			ss >> nor[0] >> nor[1] >> nor[2];

			normals.push_back(nor);
		} else if (top == "vt") {
			float uv[2];

			ss >> uv[0] >> uv[1];

			uvs.push_back(uv);
		} else if (top == "f") {
			for (int i = 0; i < 3; ++i) {
				Object::Vertex ver;
				std::string str;
				ss >> str;

				str;
			}

		} else {
			continue;
		}

		std::cout << line << std::endl;
	}

	return nullptr;
}
