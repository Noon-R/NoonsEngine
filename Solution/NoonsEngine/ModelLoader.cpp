#include "ModelLoader.h"

#include "StringReplacer.h"

//3角形ポリゴン限定
//UV情報、法線情報がそろっている場合のものだけ
//.mtlは読み込んでいない
std::pair<std::vector<Noon::GraphicsCore::Vertex>, int> LoadObjFile(char const* name)
{
	std::vector<Noon::GraphicsCore::Vertex> vertecies;
	std::vector<std::array<float, 3>> poses;
	std::vector<std::array<float, 3>> normals;
	std::vector<std::array<float, 2>> uvs;

	std::string filePath = "./Models/" + std::string(name);

	std::ifstream objFIle(filePath,std::ios::in);
	std::string line;

	std::cout << filePath << std::endl;


	if (objFIle.fail()) {
		std::cout << "Could not Find File or Read File" << std::endl;
		std::cout << "Make Sure Of FileName and Directory" << std::endl;
		return std::make_pair(vertecies,0);
	}

	//１行ずつなんのデータかの確認

	/*
		v : 頂点座標
		vn: 法線ベクトル情報
		vt: UV情報
		f : ポリゴン情報
	*/

	while (std::getline(objFIle,line)) {

		std::stringstream ss;
		std::string top;

		ss << line;
		ss >> top;
		
		if (top == "v") {
			std::array<float, 3> pos;

			ss >> pos[0] >> pos[1] >> pos[2];

			poses.push_back(pos);
		}else if (top == "vn") {
			std::array<float, 3> nor;

			ss >> nor[0] >> nor[1] >> nor[2];

			normals.push_back(nor);
		} else if (top == "vt") {
			std::array<float, 2> uv;

			ss >> uv[0] >> uv[1];

			uvs.push_back(uv);
		} else if (top == "f") {
			std::string str;
			for (int i = 0; i < 3; ++i) {
				Noon::GraphicsCore::Vertex ver ;
				
				for (int j = 0; j < 4; ++j) {
					ver.color[j] = 1.0f;
				}

				ss >> str;
				Noon::Util::ReplaceAllChar(str,"/"," ");
				int p, u, n;
				std::stringstream vs;
				vs << str;
				vs >> p >> u >> n;

				for (int j = 0; j < 3; ++j) {
					ver.position[j] = poses[p-1][j];
				}

				for (int j = 0; j < 2; ++j) {
					ver.uv[j] = uvs[u-1][j];
				}

				for (int j = 0; j < 3; ++j) {
					ver.normal[j] = normals[n-1][j];
				}
				
				vertecies.push_back(ver);
			}
			
		} else {
			continue;
		}
		

		std::cout << line << std::endl;
	}

	return std::make_pair(vertecies, vertecies.size()); ;
}
