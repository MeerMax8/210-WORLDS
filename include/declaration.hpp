#include "pros/adi.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "pros/imu.hpp"
#include "pros/apix.h"
#include "lemlib/api.hpp"

//drivetrain
extern pros::Motor frontRight;
extern pros::Motor frontLeft;
extern pros::Motor backRight;
extern pros::Motor backLeft;
extern pros::Motor midRight;
extern pros::Motor midLeft;
extern lemlib::Chassis chassis;

//cata
extern pros::Motor cata;

//intake
extern pros::Motor intakeLeft;
extern pros::Motor intakeRight;

//inertial
extern pros::IMU inertial;

//wings
extern pros::ADIDigitalOut wing_frontLeft;
extern pros::ADIDigitalOut wing_frontRight;
extern pros::ADIDigitalOut wing_backLeft;
extern pros::ADIDigitalOut wing_backRight;

//pto
extern pros::ADIDigitalOut pto;

//lift
extern pros::ADIDigitalOut lift;

//hang
extern pros::ADIDigitalOut hang;

//controller
extern pros::Controller controller;

//led
extern pros::ADILed led;

//declared motorgroups for odom and pid
extern pros::MotorGroup left_side_motors;
extern pros::MotorGroup right_side_motors;