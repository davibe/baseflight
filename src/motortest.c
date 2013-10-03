#include "motortest.h"

uint8_t motortest_index = 0;


bool motortest_is_enabled()
{
    // motortest is active when armed and BOXMOTORTEST is active
    return (f.ARMED) && (rcOptions[BOXMOTORTEST]);
}


void motortest_check_sticks()
{
    // TODO: need to figure out a nice way to read sticks inputs
    // from outside the multiwii loop()
    
    /*
    if (rcSticks == THR_LO + ROL_LO)
        motortest_index++;

    if (rcSticks == THR_LO + ROL_HI)
        motortest_index--;
    */
}  


void motortest_loop()
{
    if (motortest_is_enabled()) {
        writeOneMotor(motortest_index, rcCommand[THROTTLE]);
        motortest_check_sticks();
    } else {
        motortest_index = 0;
    }
}
