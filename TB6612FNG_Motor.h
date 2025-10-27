//
// Created by Petre Ioan Iulian on 6/27/2025.
//

#ifndef TB6112FNG_MOTOR_H
#define TB6112FNG_MOTOR_H

#pragma once
#include <Arduino.h>
#include <stdint.h>

class TB6612FNG_Motor {
public:
    TB6612FNG_Motor(uint8_t InPin1, uint8_t InPin2 , uint8_t PWM);

    void begin() {
        pinMode(InPin1, OUTPUT);
        pinMode(InPin2, OUTPUT);
        pinMode(PWM, OUTPUT);
    }

    void forward(int speed) {
        digitalWrite(InPin1, HIGH);
        digitalWrite(InPin2, LOW);
        analogWrite(PWM, speed);
    }

    void reverse(int speed) {
        digitalWrite(InPin1, LOW);
        digitalWrite(InPin2, HIGH);
        analogWrite(PWM, speed);
    }

    void breakMotor() {
        digitalWrite(InPin1, HIGH);
        digitalWrite(InPin2, HIGH);
        analogWrite(PWM, 0);
    }

    void setSpeed(int rawSpeed) {
        int speed = map(abs(rawSpeed), 0, 100, 0, 255);
        if (rawSpeed > 0) {
            forward(speed);
        }
        else {
            reverse(-speed);
        }
    }

private:
    uint8_t InPin1;
    uint8_t InPin2;
    uint8_t PWM;

};

#endif //TB6112FNG_MOTOR_H

