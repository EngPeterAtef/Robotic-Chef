cmake_minimum_required(VERSION 3.20)
project(micro_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.pio/libdeps/uno/Servo/examples)
include_directories(.pio/libdeps/uno/Servo/examples/Knob)
include_directories(.pio/libdeps/uno/Servo/examples/Sweep)
include_directories(.pio/libdeps/uno/Servo/src)
include_directories(.pio/libdeps/uno/Servo/src/avr)
include_directories(.pio/libdeps/uno/Servo/src/mbed)
include_directories(.pio/libdeps/uno/Servo/src/megaavr)
include_directories(.pio/libdeps/uno/Servo/src/nrf52)
include_directories(.pio/libdeps/uno/Servo/src/sam)
include_directories(.pio/libdeps/uno/Servo/src/samd)
include_directories(.pio/libdeps/uno/Servo/src/stm32f4)
include_directories(.pio/libdeps/uno/Stepper/examples)
include_directories(.pio/libdeps/uno/Stepper/examples/MotorKnob)
include_directories(.pio/libdeps/uno/Stepper/examples/stepper_oneRevolution)
include_directories(.pio/libdeps/uno/Stepper/examples/stepper_oneStepAtATime)
include_directories(.pio/libdeps/uno/Stepper/examples/stepper_speedControl)
include_directories(.pio/libdeps/uno/Stepper/src)
include_directories(src)

add_executable(micro_project
        .pio/libdeps/uno/Servo/examples/Knob/Knob.ino
        .pio/libdeps/uno/Servo/examples/Sweep/Sweep.ino
        .pio/libdeps/uno/Servo/src/avr/Servo.cpp
        .pio/libdeps/uno/Servo/src/avr/ServoTimers.h
        .pio/libdeps/uno/Servo/src/mbed/Servo.cpp
        .pio/libdeps/uno/Servo/src/mbed/ServoTimers.h
        .pio/libdeps/uno/Servo/src/megaavr/Servo.cpp
        .pio/libdeps/uno/Servo/src/megaavr/ServoTimers.h
        .pio/libdeps/uno/Servo/src/nrf52/Servo.cpp
        .pio/libdeps/uno/Servo/src/nrf52/ServoTimers.h
        .pio/libdeps/uno/Servo/src/sam/Servo.cpp
        .pio/libdeps/uno/Servo/src/sam/ServoTimers.h
        .pio/libdeps/uno/Servo/src/samd/Servo.cpp
        .pio/libdeps/uno/Servo/src/samd/ServoTimers.h
        .pio/libdeps/uno/Servo/src/stm32f4/Servo.cpp
        .pio/libdeps/uno/Servo/src/stm32f4/ServoTimers.h
        .pio/libdeps/uno/Servo/src/Servo.h
        .pio/libdeps/uno/Stepper/examples/MotorKnob/MotorKnob.ino
        .pio/libdeps/uno/Stepper/examples/stepper_oneRevolution/stepper_oneRevolution.ino
        .pio/libdeps/uno/Stepper/examples/stepper_oneStepAtATime/stepper_oneStepAtATime.ino
        .pio/libdeps/uno/Stepper/examples/stepper_speedControl/stepper_speedControl.ino
        .pio/libdeps/uno/Stepper/src/Stepper.cpp
        .pio/libdeps/uno/Stepper/src/Stepper.h
        misc_c_files/testfunc.cpp
        src/main.cpp
        src/Task2.ino)
