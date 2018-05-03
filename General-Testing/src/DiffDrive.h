#ifndef SRC_DIFFDRIVE_H
#define SRC_DIFFDRIVE_H

#include <WPILib.h>
#include "ctre/Phoenix.h"
#include <Definitions.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

class DiffDrive : public DifferentialDrive {
public:
	DiffDrive(int leftMotor, int rightMotor);
	void Init(void);
	void Update(float leftSpeed, float rightSpeed);
	int getDriveType(void);
	void setDriveType(int driveType);
protected:
	~DiffDrive(void);
private:
	WPI_TalonSRX a_leftTalon;
	WPI_TalonSRX a_rightTalon;


	DifferentialDrive a_DifferentialDrive; //Default Differential Drive First provides.

	int driveType;
};

#endif
