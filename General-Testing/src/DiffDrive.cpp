#include <DiffDrive.h>
#include <WPILib.h>
#include "ctre/Phoenix.h"
#include <Definitions.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

DiffDrive::DiffDrive(int leftMotor, int rightMotor):
a_leftTalon(leftMotor),
a_rightTalon(rightMotor),

a_DifferentialDrive(a_leftTalon, a_rightTalon)
{
	driveType = 0;
}

void DiffDrive::Init(void)
{

}

void DiffDrive::Update(float leftSpeed, float rightSpeed)
{
	switch(driveType) {
		case 0: //Tank Drive with two flightsticks in ports 1 and 2
			a_DifferentialDrive.TankDrive(leftSpeed, rightSpeed, false);
			break;
		case 1: //Arcade Drive with the flightstick in port 2
			a_DifferentialDrive.ArcadeDrive(leftSpeed, rightSpeed, false);
			break;

	}

}

int DiffDrive::getDriveType(void)
{
	return driveType;
}

void DiffDrive::setDriveType(int type)
{
	driveType = type;
}

DiffDrive::~DiffDrive(void)
{

}
