#ifndef SRC_ROBOT_H
#define SRC_ROBOT_H

#include <DiffDrive.h>
#include <WPILib.h>
#include "ctre/Phoenix.h"
#include <IterativeRobot.h>

class Woodie : public IterativeRobot {
public:
	Woodie(void);
	void RobotInit(void);
	void RobotPeriodic(void);

	void DisabledInit(void);
	void DisabledPeriodic(void);

	void TeleopInit(void);
	void TeleopPeriodic(void);

	void AutonomousInit(void);
	void AutonomousPeriodic(void);
	~Woodie(void);

private:
	Joystick a_Joystick1; // Flightstick in Slot 1
	Joystick a_Joystick2; // Flightstick in Slot 2

	DiffDrive a_DiffDrive; // (Left Motor, Right Motor)
};

#endif
