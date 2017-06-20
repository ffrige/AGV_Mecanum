#include "misc.h"

/* calculates the direct kinematic transformations for the AGV */
unsigned short AGV_Kin_Direct(AGV_Type* AGV)
{
	
	/* check mechanical parameters */
	if ((AGV->Mech.WheelRadius <= 0)||(AGV->Mech.Dx <= 0)||(AGV->Mech.Dy <= 0))
	{
		return ERR_AGV_MECH;
	}

	/* check that wheels speeds are correctly set */
	if (fabs(AGV->Wheel_Speed.W1 + AGV->Wheel_Speed.W2 - AGV->Wheel_Speed.W3 - AGV->Wheel_Speed.W4) >= AGV_EPSILON)
	{
		return ERR_AGV_WHEEL_SPEED;
	}
		
	AGV->Local_Speed.Vw = AGV->Mech.WheelRadius * PI / 180.0f *(AGV->Wheel_Speed.W1 - AGV->Wheel_Speed.W2 - AGV->Wheel_Speed.W3 + AGV->Wheel_Speed.W4) / 4.0 /(AGV->Mech.Dx + AGV->Mech.Dy);
	AGV->Local_Speed.Vx = AGV->Mech.WheelRadius * PI / 180.0f *(-AGV->Wheel_Speed.W1 + AGV->Wheel_Speed.W2 - AGV->Wheel_Speed.W3 + AGV->Wheel_Speed.W4) / 4.0;
	AGV->Local_Speed.Vy = AGV->Mech.WheelRadius * PI / 180.0f *(AGV->Wheel_Speed.W1 + AGV->Wheel_Speed.W2 + AGV->Wheel_Speed.W3 + AGV->Wheel_Speed.W4) / 4.0;
	
	//convert from radians to degrees
	AGV->Local_Speed.Vw *= (180.0f / PI);
	
	//convert AGV local speed into global system
	AGV_ToGlobal((AGV_Type*) AGV);
	
	return ERR_AGV_OK;

}
