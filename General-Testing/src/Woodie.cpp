#include <WPILib.h>
#include "ctre/Phoenix.h"
#include <Definitions.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Woodie.h>

Woodie::Woodie(void):
a_Joystick1(JOYSTICK1_PORT),
a_Joystick2(JOYSTICK2_PORT),

a_leftTalon(LEFT_TALON),
a_rightTalon(RIGHT_TALON),

a_DriveTrain(a_leftTalon, a_rightTalon)

{
	SmartDashboard::init();
}

void Woodie::RobotInit(void)
{

}

void Woodie::RobotPeriodic(void)
{

}

void Woodie::DisabledInit(void)
{
	a_DriveTrain.TankDrive(0, 0, false); //Should stop when disabled.
}

void Woodie::DisabledPeriodic(void)
{
	SmartDashboard::PutBoolean("Enabled", false);
}

void Woodie::TeleopInit(void)
{

}

void Woodie::TeleopPeriodic(void)
{
	SmartDashboard::PutBoolean("Enabled", true);
	a_DriveTrain.TankDrive(a_Joystick1.GetRawAxis(1), a_Joystick2.GetRawAxis(1), false);
}

void Woodie::AutonomousInit(void)
{
	a_DriveTrain.TankDrive(0, 0, false); //Robot will do nothing
}

void Woodie::AutonomousPeriodic(void)
{

}

Woodie::~Woodie(void)
{

}

START_ROBOT_CLASS(Woodie); // Call to Task Main();
