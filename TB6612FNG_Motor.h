//
// Created by Petre Ioan Iulian on 6/27/2025.
//

#ifndef TB6112FNG_MOTOR_H
#define TB6112FNG_MOTOR_H

#pragma once
#include <Arduino.h>

class TB6612FNG_Motor {
public:
    TB6612FNG_Motor(uint8_t InPin1, uint8_t InPin2 , uint8_t PWM)
        : in1(InPin1), in2(InPin2), pwm(PWM) {}

    void begin() {
        pinMode(in1, OUTPUT);
        pinMode(in2, OUTPUT);
        pinMode(pwm, OUTPUT);
    }

    void forward(int speed) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(pwm, speed);
    }

    void reverse(int speed) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        analogWrite(pwm, speed);
    }

    void breakMotor() {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, HIGH);
        analogWrite(pwm, 0);
    }

    void setSpeed(int rawSpeed) {
        int speed = map(abs(rawSpeed), 0, 100, 0, 255);
        if (rawSpeed > 0) {
            forward(speed);
        }
        else {
            reverse(speed);
        }
    }

private:
    uint8_t in1;
    uint8_t in2;
    uint8_t pwm;

};

#endif //TB6112FNG_MOTOR_H

