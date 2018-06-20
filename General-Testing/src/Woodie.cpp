#include <WPILib.h>
#include "ctre/Phoenix.h"
#include <Definitions.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Woodie.h>
#include <DiffDrive.h>

Woodie::Woodie(void):
a_Joystick1(JOYSTICK1_PORT),
a_Joystick2(JOYSTICK2_PORT),
a_GameCubeController(GAMECUBE_PORT),

a_DiffDrive(LEFT_TALON, RIGHT_TALON)

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
	a_DiffDrive.Update(0, 0); // Should stop when disabled.
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

	if(a_Joystick2.GetRawButton(1))
	{
		a_DiffDrive.setDriveType(0); // Tank Drive
	}

	if(a_Joystick2.GetRawButton(2))
	{
		a_DiffDrive.setDriveType(1); // Arcade Drive
	}

	if(a_GameCubeController.GetRawButton(2))
	{
		a_DiffDrive.setDriveType(2); // Tank Drive w/ Gamecube Controller
	}

	if(a_DiffDrive.getDriveType() == 0)
	{
		SmartDashboard::PutString("Drive Mode:", "Tank Drive");
		a_DiffDrive.Update(a_Joystick2.GetRawAxis(1), a_Joystick1.GetRawAxis(1));
	}

	if(a_DiffDrive.getDriveType() == 1)
	{
		SmartDashboard::PutString("Drive Mode:", "Arcade Drive");
		a_DiffDrive.Update(a_Joystick2.GetRawAxis(1), a_Joystick2.GetRawAxis(0));
	}

	if(a_DiffDrive.getDriveType() == 2)
	{
		SmartDashboard::PutString("Drive Mode:", "Gamecube");
		a_DiffDrive.Update(a_GameCubeController.GetRawAxis(2), a_GameCubeController.GetRawAxis(1)); // Theo the two joysticks on the gamecube controller
	}
}

void Woodie::AutonomousInit(void)
{

}

void Woodie::AutonomousPeriodic(void)
{
	a_DiffDrive.setDriveType(0);
	a_DiffDrive.Update(0, 0); //Robot will do nothing
}

Woodie::~Woodie(void)
{

}

START_ROBOT_CLASS(Woodie); // Call to Task Main();
