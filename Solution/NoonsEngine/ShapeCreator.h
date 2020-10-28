#pragma once

#include <vector>

#include "Shape.h"
#include "SolidShape.h"
#include "SolidShapeIndex.h"
#include "AWindowBase.h"
#include "Object.h"

Shape* CreateSolidSphere(AWindowBase* const window, const int slices, const int stacks);
Shape* CreateSolidCube(AWindowBase* const window);
