//
// Created by Petre Ioan Iulian on 6/27/2025.
//

#ifndef TB6612FNG_MOTORSHIELD_H
#define TB6612FNG_MOTORSHIELD_H

#pragma once
#include <Arduino.h>
#include "TB6612FNG_Motor.h"


class TB6612FNG_MotorShield {
public:
    TB6612FNG_MotorShield(uint8_t M1In1, uint8_t M1In2, uint8_t PWM1,
                          uint8_t M2In1, uint8_t M2In2, uint8_t PWM2)
    :M1(M1In1, M1In2, PWM1),
     M2(M2In1, M2In2, PWM2) {}

    void begin() {
        M1.begin();
        M2.begin();
    }

    void setM1Speed(int speed) {
        M1.setSpeed(speed);
    }

    void setM2Speed(int speed) {
        M2.setSpeed(speed);
    }

    void fullbreak() {
        M1.breakMotor();
        M2.breakMotor();
    }

private:
    TB6612FNG_Motor M1, M2;
};

#endif //TB6612FNG_MOTORSHIELD_H
