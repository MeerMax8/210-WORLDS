#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "api.h"
#include "lemlib/api.hpp"
#include "declaration.hpp"
#include "pros/rotation.hpp"

//drivetrain/chassis
pros::Motor frontRight(12, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor frontLeft(19, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backRight(14, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backLeft(17, pros::E_MOTOR_GEARSET_06,true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor midRight(15,pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor midLeft(18, pros::E_MOTOR_GEARSET_06,true, pros::E_MOTOR_ENCODER_COUNTS);
//puncher
pros::Motor cata(1, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
//intake
pros::Motor intakeLeft(20, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intakeRight(11,pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
//inertial
pros::Imu inertial (1);
//wings
pros::ADIDigitalOut wing_frontLeft('A');
pros::ADIDigitalOut wing_frontRight('A');
pros::ADIDigitalOut wing_backLeft('A');
pros::ADIDigitalOut wing_backRight('A');
//pto
pros::ADIDigitalOut pto('A');
//lift
pros::ADIDigitalOut lift('A');
//hang
pros::ADIDigitalOut hang('A');
//controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);
//led
pros::ADILed led('E', 64);

pros::MotorGroup left_side_motors({frontLeft, midLeft, backLeft});
pros::MotorGroup right_side_motors({frontRight, midRight, backRight});

lemlib::Drivetrain_t drivetrain {
    &left_side_motors, // left drivetrain motors
    &right_side_motors, // right drivetrain motors
    9.5, // track width in inches <- previously 11 inches
    2.75, // wheel diameter
    450 // wheel rpm
};

lemlib::OdomSensors_t sensors {
    nullptr, // vertical tracking wheel 1 (motor)
    nullptr, // vertical tracking wheel 2 (motor)
    nullptr, // horizontal tracking wheel 1 (none)
    nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    &inertial, // inertial sensor
};

lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};

lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);