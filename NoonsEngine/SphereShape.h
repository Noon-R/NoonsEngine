#pragma once

#include <vector>

#include "Shape.h"
#include "SolidShapeIndex.h"
#include "WindowBase.h"
#include "Object.h"

Shape* CreateSolidSphere(WindowBase* const window, const int slices, const int stacks);

