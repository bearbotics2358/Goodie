#ifndef SRC_BLASTER_H_
#define SRC_BLASTER_H_

#include "ctre/Phoenix.h"
#include <WPILib.h>
#include <Definitions.h>

class Blaster {
public:
	Blaster(void);
	void UpdateAngle(int angle); // Unused until pot is added
	void SetLiftSpeed(double speed);
	void Fire(void);
	void StopFiring(void);
	bool IsFiring(void);
	~Blaster(void);
private:
	WPI_TalonSRX a_liftMotor;
	DigitalOutput a_Relay;
};

#endif /* SRC_BLASTER_H_ */
