#include <WPILib.h>
#include "ctre/Phoenix.h"
#include <Definitions.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Woodie.h>
#include <DiffDrive.h>

Woodie::Woodie(void):
a_leftEncoder(LEFT_ENCODER_A, LEFT_ENCODER_B, true),
a_rightEncoder(RIGHT_ENCODER_A, RIGHT_ENCODER_B, false),
a_Joystick1(JOYSTICK1_PORT),
a_Joystick2(JOYSTICK2_PORT),
a_GameCubeController(GAMECUBE_PORT),

a_DiffDrive(LEFT_TALON, RIGHT_TALON),
a_Blaster()

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
	a_leftEncoder.Reset();
	a_rightEncoder.Reset();
}

void Woodie::TeleopPeriodic(void)
{
	int driveMode;

	if(a_Joystick2.GetRawButton(1))
	{
		a_DiffDrive.setDriveType(0); // Tank Drive
	}

	if(a_Joystick2.GetRawButton(2))
	{
		a_DiffDrive.setDriveType(1); // Arcade Drive
	}

	if(a_GameCubeController.GetRawButton(3))
	{
		if(a_Blaster.IsFiring() == false)
		{
			a_Blaster.ToggleFiring();
		}
	}
	else
	{
		if(a_Blaster.IsFiring())
		{
			a_Blaster.ToggleFiring();
		}
	}

	if(a_GameCubeController.GetRawButton(2))
	{
		a_DiffDrive.setDriveType(2); // Tank Drive w/ Gamecube Controller
	}

	if(a_DiffDrive.getDriveType() == 0)
	{
		driveMode = 0;
		a_DiffDrive.Update(a_Joystick1.GetRawAxis(1), a_Joystick2.GetRawAxis(1));
	}

	if(a_DiffDrive.getDriveType() == 1)
	{
		driveMode = 1;
		a_DiffDrive.Update(a_Joystick2.GetRawAxis(1), a_Joystick2.GetRawAxis(0));
	}

	if(a_DiffDrive.getDriveType() == 2)
	{
		driveMode = 2;
		a_DiffDrive.Update(a_GameCubeController.GetRawAxis(1), a_GameCubeController.GetRawAxis(2)); // Theo the two joysticks on the gamecube controller
	}

	SmartDashboard::PutBoolean("Enabled", true);
	SmartDashboard::PutBoolean("Firing?", a_Blaster.IsFiring());
	SmartDashboard::PutNumber("Left Encoder Value", a_leftEncoder.GetRaw());
	SmartDashboard::PutNumber("Right Encoder Value", a_rightEncoder.GetRaw());

	if(driveMode == 0)
	{
		SmartDashboard::PutString("Drive Mode:", "Tank Drive");
	}
	else if(driveMode == 1)
	{
		SmartDashboard::PutString("Drive Mode:", "Arcade Drive");
	}
	else if(driveMode == 2)
	{
		SmartDashboard::PutString("Drive Mode:", "GameCube Tank");
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
