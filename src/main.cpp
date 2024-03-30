#include "main.h"
#include "lemlib/api.hpp"
#include "autonomous.hpp"
#include "gif-pros/gifclass.hpp"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	//pros::lcd::initialize(); <-- pros disablement for gif integration
	chassis.calibrate(); //odom initialize <-- WATCH OUT FOR DEBUG WHILE LOOP
	wing_frontLeft.set_value(false); //piston default state
	wing_frontRight.set_value(false);
	wing_backLeft.set_value(false);
	wing_backRight.set_value(false);
	pto.set_value(false);
	lift.set_value(false);
	hang.set_value(false);
//insert initial calibration for led selection?
}



void disabled() {}

void competition_initialize() {}

void autonomous() {
	WPclose(); //1
	// RUSH_six_ball_far(); //2
	// CONS_six_ball_far(); //3
	// two_ball_close(); //null
	// skills(); //4
}

void opcontrol() {
	//refer to initialize to piston default declarations
	lv_obj_t* obj = lv_obj_create(lv_scr_act(), NULL);
	lv_obj_set_size(obj, 480, 240);
	lv_obj_set_style(obj, &lv_style_transp);
	lv_obj_align(obj, NULL, LV_ALIGN_CENTER, 0, 0);
	Gif gif("/usd/moon.gif", obj); //moon or meow
	
	float driveSpeed = 1;
	float turnSpeed = 1;

	while (true) {
		intakeOP();

		//drive function
		frontRight.move(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)*driveSpeed - controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)*turnSpeed);
		frontLeft.move(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)*driveSpeed + controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)*turnSpeed);
		backRight.move(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)*driveSpeed - controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)*turnSpeed);
		backLeft.move(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)*driveSpeed + controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)*turnSpeed);
		midRight.move(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)*driveSpeed - controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)*turnSpeed);
		midLeft.move(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)*driveSpeed + controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)*turnSpeed);

		pros::delay(10);
	}
}
