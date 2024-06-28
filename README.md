# Dual Axis Solar Tracker

## Overview

The goal of this project is to create an automated solar panel tracking system using an Arduino.
The system uses servo motors to adjust the position of the solar panel based on the intensity of 
light detected by Light Dependent Resistors (LDRs). This ensures that the solar panel is always oriented
towards the direction of maximum sunlight, thereby optimizing energy absorption.

## How It Works

- **Servo Motors**: Two servos are used to control the horizontal and vertical angles of the solar panel.
- **Light Dependent Resistors (LDRs)**: Four LDRs are placed at different positions to detect the light intensity from various directions.
- **Analog Readings**: The Arduino reads the analog values from the LDRs.
- **Position Adjustment**: Based on the readings, the Arduino calculates the average light intensity for the top, bottom, left, and right directions. It then adjusts the angles of the servos to point the solar panel towards the direction with the highest light intensity.

## Code Explanation

- **Initialization**: The servos are attached to specific pins on the Arduino, and their initial positions are set.
- **Main Loop**: 
  - The Arduino continuously reads the light intensity values from the LDRs.
  - It calculates the average light intensity for the top and bottom, and the left and right directions.
  - It adjusts the vertical and horizontal angles of the solar panel based on these averages to maximize sunlight absorption.

This project demonstrates a simple yet effective way to automate the orientation of a solar panel using basic components and an Arduino.
