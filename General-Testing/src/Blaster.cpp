#include <WPILib.h>
#include <Definitions.h>
#include "ctre/Phoenix.h"
#include <Blaster.h>

Blaster::Blaster(void):
a_liftMotor(LIFT_TALON),
a_Relay(RELAY_PORT)
{

}

void Blaster::UpdateAngle(int angle)
{

}

void Blaster::ToggleFiring(void)
{
	if(a_Relay.Get())
	{
		a_Relay.Set(false);
	}
	else
	{
		a_Relay.Set(true);
	}
}

bool Blaster::IsFiring(void)
{
	bool ret = a_Relay.Get();
	return ret;
}

Blaster::~Blaster(void)
{

}
