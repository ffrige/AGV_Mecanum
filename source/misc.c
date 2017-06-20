#include "misc.h"

/* convert world speed into local speed */
unsigned short AGV_ToLocal(AGV_Type* AGV)
{

	AGV->Local_Speed.Vx = AGV->Path_Speed.Vx * cosd(AGV->Path_Angle) + AGV->Path_Speed.Vy * sind(AGV->Path_Angle);
	AGV->Local_Speed.Vy = -AGV->Path_Speed.Vx * sind(AGV->Path_Angle) + AGV->Path_Speed.Vy * cosd(AGV->Path_Angle);
	AGV->Local_Speed.Vw = -AGV->Path_Speed.Vw;
		
	return ERR_AGV_OK;

}


/* convert local speed into world speed */
unsigned short AGV_ToGlobal(AGV_Type* AGV)
{

	AGV->Path_Speed.Vx = AGV->Local_Speed.Vx * cosd(AGV->Path_Angle) - AGV->Local_Speed.Vy * sind(AGV->Path_Angle);
	AGV->Path_Speed.Vy = AGV->Local_Speed.Vx * sind(AGV->Path_Angle) + AGV->Local_Speed.Vy * cosd(AGV->Path_Angle);
	AGV->Path_Speed.Vw = -AGV->Local_Speed.Vw;
		
	return ERR_AGV_OK;

}
