#include "misc.h"

/* calculates the inverse kinematic transformations for the AGV */
unsigned short AGV_Kin_Inverse(AGV_Type* AGV)
{

	/* check mechanical parameters */
	if ((AGV->Mech.WheelRadius <= 0)||(AGV->Mech.Dx <= 0)||(AGV->Mech.Dy <= 0))
	{
		return ERR_AGV_MECH;
	}

	//convert AGV global speed into local system
	AGV_ToLocal((AGV_Type*) AGV);
		
	//convert angular speed from degrees to radiant
	AGV->Local_Speed.Vw *= (PI / 180.0f);

	//wheel speed in deg/s!
	AGV->Wheel_Speed.W1 = (AGV->Local_Speed.Vy - AGV->Local_Speed.Vx + AGV->Local_Speed.Vw * (AGV->Mech.Dx + AGV->Mech.Dy)) / AGV->Mech.WheelRadius * 180.0f / PI;
	AGV->Wheel_Speed.W2 = (AGV->Local_Speed.Vy + AGV->Local_Speed.Vx - AGV->Local_Speed.Vw * (AGV->Mech.Dx + AGV->Mech.Dy)) / AGV->Mech.WheelRadius * 180.0f / PI;
	AGV->Wheel_Speed.W3 = (AGV->Local_Speed.Vy - AGV->Local_Speed.Vx - AGV->Local_Speed.Vw * (AGV->Mech.Dx + AGV->Mech.Dy)) / AGV->Mech.WheelRadius * 180.0f / PI;
	AGV->Wheel_Speed.W4 = (AGV->Local_Speed.Vy + AGV->Local_Speed.Vx + AGV->Local_Speed.Vw * (AGV->Mech.Dx + AGV->Mech.Dy)) / AGV->Mech.WheelRadius * 180.0f / PI;
	
	return ERR_AGV_OK;

}

