#include "main.h"
#include "pros/misc.h"
#include "intake.hpp"

float intakeSpeed = 1;
float autonIntakeSpeed = 1;

void intakeOP(){
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) { //intake
		intakeLeft.move_voltage(12000*intakeSpeed);
		intakeRight.move_voltage(12000*intakeSpeed);
	}
	else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){//outtake
		intakeLeft.move_voltage(-12000*intakeSpeed);
		intakeRight.move_voltage(-12000*intakeSpeed);
	}else{
		intakeLeft.move_voltage(0);
		intakeRight.move_voltage(0);
	}
}