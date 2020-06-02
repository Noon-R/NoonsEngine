#include "ModelLoader.h"


Object::Vertex* LoadObjFile(char const* name)
{
	std::vector<Object::Vertex> vertecies;
	std::vector<float[3]> poses;
	std::vector<float[3]> normal;
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

		if (line[0] == 'v' && line[1] == ' ') {
			std::stringstream ss;
			Object::Vertex vertex;

			ss << line.substr(2);

			ss >> vertex.position[0] >> vertex.position[1] >> vertex.position[2];

			vertecies.push_back(vertex);
		}

		if (line[0] == 'v' && line[1] == ' ') {
			std::stringstream ss;
			Object::Vertex vertex;

			ss << line.substr(2);

			ss >> vertex.position[0] >> vertex.position[1] >> vertex.position[2];

			vertecies.push_back(vertex);
		}

		std::cout << line << std::endl;
	}

	return nullptr;
}
