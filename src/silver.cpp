#include "main.h"
#include "declaration.hpp"
#include "pros/misc.h"

//silver isolated functions

bool liftToggle = 0;
bool ptoToggle = 0;

void ptoOP(){
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)){ //lift hook/blocker
        liftToggle = !liftToggle;
    }
    if (liftToggle == 1){
        lift.set_value(true);
    } else {
        lift.set_value(false);
    }

    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){ //pto actuation
        ptoToggle = !ptoToggle;
    }
    if (ptoToggle == 1){
        pto.set_value(true);
    } else {
        pto.set_value(false);
    }
}

void hangOP(){ //B-tier is NON-TOGGLE <- HOLD
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){ //hang actuation
        hang.set_value(true);
    }
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)){ //default occurence
        hang.set_value(false);
    }
}