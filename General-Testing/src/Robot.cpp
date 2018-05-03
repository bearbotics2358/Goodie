#include <Robot.h>
#include <WPILib.h>
#include "ctre/Phoenix.h"
#include <Definitions.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

Robot::Robot(void):
a_Joystick1(JOYSTICK1_PORT),
a_Joystick2(JOYSTICK2_PORT),

a_leftTalon(LEFT_TALON),
a_rightTalon(RIGHT_TALON),

a_DriveTrain(a_leftTalon, a_rightTalon)

{
	SmartDashboard::init();
}

void Robot::RobotInit(void)
{

}

void Robot::RobotPeriodic(void)
{

}

void Robot::DisabledInit(void)
{
	a_DriveTrain.TankDrive(0, 0, false); //Should stop when disabled.
}

void Robot::DisabledPeriodic(void)
{
	SmartDashboard::PutBoolean("Enabled", false);
}

void Robot::TeleopInit(void)
{

}

void Robot::TeleopPeriodic(void)
{
	SmartDashboard::PutBoolean("Enabled", true);
	a_DriveTrain.TankDrive(a_Joystick1.GetRawAxis(1), a_Joystick2.GetRawAxis(2), false);
}

void Robot::AutonomousInit(void)
{
	a_DriveTrain.TankDrive(0, 0, false); //Robot will do nothing
}

void Robot::AutonomousPeriodic(void)
{

}

Robot::~Robot(void)
{

}
