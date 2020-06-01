#include "ModelLoader.h"


Object::Vertex* LoadObjFile(char const* name)
{
	std::vector<Object::Vertex> vertecies;

	std::string filePath = "./Models/" + std::string(name);

	std::ifstream objFIle(filePath,std::ios::in);
	std::string line;

	std::cout << filePath << std::endl;


	if (objFIle.fail()) {
		std::cout << "Could not Find File or Read File" << std::endl;
		return nullptr;
	}

	while (std::getline(objFIle,line)) {
		std::cout << line << std::endl;
	}

	return nullptr;
}
