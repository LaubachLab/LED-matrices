This folder contains files necessary to create a platform of three LED matrices for generating visual stimuli sets. The platform features open-source components that are flexible and customizable. Links provided in this document, code, and manuscript were retrieved December 12, 2020. The file list is as follows:

- LEDMatrix-Addressing.png: an image of the addresses used in our platform setup (x70, x71, and x74). More information about assembling and addressing the LED matrix backpacks are available here: https://learn.adafruit.com/adafruit-led-backpack/1-2-8x8-matrix-assembly  https://learn.adafruit.com/adafruit-led-backpack/changing-i2c-address

- LED-Matrix-Holder-Part1.stl: a stl file for the main 3D printed LED matrix holder developed by JW. Connected to part 2 (essentially a door) with screws. 

- LED-Matrix-Holder-Part1.stl: a stl file for the door of the 3D printed LED matrix holder developed by JW. Connected to part 1 with screws. 

- StimCodes.png: a table of which input pins must be triggered with 5V+ to turn on different stimulus sets across the matrices. The 2 and 8 refer to the number of pixels that are lit at random in a fast sequence, giving the appearance that 2 or 8 pixels are 'dancing'. 

- wiringDiagram.png: Figure 1 from the manuscript. Shows how pull down resistors (10k) are implemented with the digital Arduino pins to ensure they are not 'floating', causing random stimulus sets to display in the absence of inputs. The grounds on the breadboard should come from the Arduino and additionally from the source of the TTL input. In our case, we use a solid state relay (Crouzet) to toggle a 28V+ input signal from a MedAssociates SmartControl panel to a 5V+ output signal to set the digital pins on the arduino to high. When the signal is turned off, the pull down resistors return the digital pins to ground. For more information about this specific setup, see FullSetUp.png.

- FullSetUp.png: a modified version of Figure 1 to include the relay and MedAssociates SmartControl panel. Parts in for this portion of the set up are available from Mouser Electronics (mouser.com). For a list of these parts or example MPC protocols, contact the authors. 

- VisualStimuli-Arduino-eNeuro: a folder containing the Arduino code to upload on the Arudino Uno. The code depends on the Adafruit_GFX library (https://learn.adafruit.com/adafruit-gfx-graphics-library) and Adafruit_LEDBackpack library (https://learn.adafruit.com/adafruit-led-backpack/downloads). This code is designed to work with three matrices with different addresses based on four inputs from the digital arduino pins. For specifics about the addressing see LEDMatrix-Addressing.png. For specifics about which input combinations are necessary to generate different stimulus sets, see StimCodes.png.

- optional-Nosepoke: a folder containing the .stl files for a mountable nosepoke (nosepoke.stl) and port block (nosepoke-block.stl; useful for behavior shaping). The square slots are designed to hold IR Break Beam Sensor - 3mm LEDs (https://www.adafruit.com/product/2167).
