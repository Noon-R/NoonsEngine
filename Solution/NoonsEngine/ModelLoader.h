#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <array>

#include "Object.h"

std::pair<std::vector<Noon::GraphicsCore::Vertex>, int> LoadObjFile(char const* name);

