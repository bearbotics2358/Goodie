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

void Blaster::SetLiftSpeed(double speed)
{
	a_liftMotor.Set(speed);
}

void Blaster::Fire(void)
{
	a_Relay.Set(true);
}

void Blaster::StopFiring(void)
{
	a_Relay.Set(false);
}

bool Blaster::IsFiring(void)
{
	bool ret = a_Relay.Get();
	return ret;
}

Blaster::~Blaster(void)
{

}
