cmake_minimum_required(VERSION 3.20)
project(Robotic_Chef)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(micro_project/.pio/libdeps/uno/Servo/examples)
include_directories(micro_project/.pio/libdeps/uno/Servo/examples/Knob)
include_directories(micro_project/.pio/libdeps/uno/Servo/examples/Sweep)
include_directories(micro_project/.pio/libdeps/uno/Servo/src)
include_directories(micro_project/.pio/libdeps/uno/Servo/src/avr)
include_directories(micro_project/.pio/libdeps/uno/Servo/src/mbed)
include_directories(micro_project/.pio/libdeps/uno/Servo/src/megaavr)
include_directories(micro_project/.pio/libdeps/uno/Servo/src/nrf52)
include_directories(micro_project/.pio/libdeps/uno/Servo/src/sam)
include_directories(micro_project/.pio/libdeps/uno/Servo/src/samd)
include_directories(micro_project/.pio/libdeps/uno/Servo/src/stm32f4)
include_directories(micro_project/.pio/libdeps/uno/Stepper/examples)
include_directories(micro_project/.pio/libdeps/uno/Stepper/examples/MotorKnob)
include_directories(micro_project/.pio/libdeps/uno/Stepper/examples/stepper_oneRevolution)
include_directories(micro_project/.pio/libdeps/uno/Stepper/examples/stepper_oneStepAtATime)
include_directories(micro_project/.pio/libdeps/uno/Stepper/examples/stepper_speedControl)
include_directories(micro_project/.pio/libdeps/uno/Stepper/src)
include_directories(micro_project/src)

add_executable(Robotic_Chef
        micro_project/.pio/libdeps/uno/Servo/examples/Knob/Knob.ino
        micro_project/.pio/libdeps/uno/Servo/examples/Sweep/Sweep.ino
        micro_project/.pio/libdeps/uno/Servo/src/avr/Servo.cpp
        micro_project/.pio/libdeps/uno/Servo/src/avr/ServoTimers.h
        micro_project/.pio/libdeps/uno/Servo/src/mbed/Servo.cpp
        micro_project/.pio/libdeps/uno/Servo/src/mbed/ServoTimers.h
        micro_project/.pio/libdeps/uno/Servo/src/megaavr/Servo.cpp
        micro_project/.pio/libdeps/uno/Servo/src/megaavr/ServoTimers.h
        micro_project/.pio/libdeps/uno/Servo/src/nrf52/Servo.cpp
        micro_project/.pio/libdeps/uno/Servo/src/nrf52/ServoTimers.h
        micro_project/.pio/libdeps/uno/Servo/src/sam/Servo.cpp
        micro_project/.pio/libdeps/uno/Servo/src/sam/ServoTimers.h
        micro_project/.pio/libdeps/uno/Servo/src/samd/Servo.cpp
        micro_project/.pio/libdeps/uno/Servo/src/samd/ServoTimers.h
        micro_project/.pio/libdeps/uno/Servo/src/stm32f4/Servo.cpp
        micro_project/.pio/libdeps/uno/Servo/src/stm32f4/ServoTimers.h
        micro_project/.pio/libdeps/uno/Servo/src/Servo.h
        micro_project/.pio/libdeps/uno/Stepper/examples/MotorKnob/MotorKnob.ino
        micro_project/.pio/libdeps/uno/Stepper/examples/stepper_oneRevolution/stepper_oneRevolution.ino
        micro_project/.pio/libdeps/uno/Stepper/examples/stepper_oneStepAtATime/stepper_oneStepAtATime.ino
        micro_project/.pio/libdeps/uno/Stepper/examples/stepper_speedControl/stepper_speedControl.ino
        micro_project/.pio/libdeps/uno/Stepper/src/Stepper.cpp
        micro_project/.pio/libdeps/uno/Stepper/src/Stepper.h
        micro_project/misc_c_files/testfunc.cpp
        micro_project/src/def.h
        micro_project/src/main.cpp
        micro_project/src/Task2.ino
        main.ino)
