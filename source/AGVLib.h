#ifndef _AGV_LIB_
#define _AGV_LIB_

/* global constants */
#define AGV_EPSILON 0.001f
#define ERR_AGV_OK 0
#define ERR_AGV_MECH 1000
#define ERR_AGV_LICENSE 1001
#define ERR_AGV_WHEEL_SPEED 1002

/* datatypes */
typedef struct AGV_Mech_Type
{
	float WheelRadius;
	float Dx;
	float Dy;
} AGV_Mech_Type;

typedef struct AGV_Speed_Type
{
	float Vx;
	float Vy;
	float Vw;
} AGV_Speed_Type;

typedef struct AGV_Wheel_Speed_Type
{
	float W1;
	float W2;
	float W3;
	float W4;
} AGV_Wheel_Speed_Type;

typedef struct AGV_Type
{
	struct AGV_Mech_Type Mech;
	struct AGV_Speed_Type Path_Speed;
	float Path_Angle;
	struct AGV_Speed_Type Local_Speed;
	struct AGV_Wheel_Speed_Type Wheel_Speed;
} AGV_Type;

/* functions */
unsigned short AGV_Kin_Inverse(struct AGV_Type* AGV);
unsigned short AGV_Kin_Direct(struct AGV_Type* AGV);
unsigned short AGV_Init(struct AGV_Type* AGV);

#endif
