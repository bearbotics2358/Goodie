#ifndef SRC_ROBOT_H
#define SRC_ROBOT_H

#include <WPILib.h>
#include "ctre/Phoenix.h"
#include <IterativeRobot.h>

class Robot : public IterativeRobot {
public:
	Robot(void);
	void RobotInit(void);
	void RobotPeriodic(void);

	void DisabledInit(void);
	void DisabledPeriodic(void);

	void TeleopInit(void);
	void TeleopPeriodic(void);

	void AutonomousInit(void);
	void AutonomousPeriodic(void);

protected:
	~Robot(void);

private:
	Joystick a_Joystick1; // Flightstick in Slot 1
	Joystick a_Joystick2; // Flightstick in Slot 2

	WPI_TalonSRX a_leftTalon; // Talon in CAN ID 0
	WPI_TalonSRX a_rightTalon; // Talon in CAN ID 1

	DifferentialDrive a_DriveTrain; // (Left Motor, Right Motor)
};

#endif
