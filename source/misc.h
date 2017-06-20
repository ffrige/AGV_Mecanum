#include "AGV_Lib.h"
#include "math.h"

#define PI 3.14159265358979f

#define sind(x) sin((x) * PI / 180.0f)
#define cosd(x) cos((x) * PI / 180.0f)

unsigned short AGV_ToLocal(AGV_Type* AGV);
unsigned short AGV_ToGlobal(AGV_Type* AGV);
