#Conway's Game of Life Project Introduction

All the LED flashlights are based on two inexpensive MSP430  micro controllers, one is used to control the top 4 bars of LEDs and the other  is used to control the side 4 bars of LEDs.  There are 16 LED lights on per top bar and 32 LED lights on per side bar. Basing on the theory of persistence of visual, we rotate the LEDs bars through a 5v motor by spinning rate  of 6 circles per second to show the image. On the top of the cylinder, 4 bars LEDs consist of four colors- red green blue yellow. So we can change the color of the clock by controlling the light’s  on and off. we use a IR infrared sensor to detect the location of the LEDs and sent signal to clock of the MSP430. The whole frame is made by ourselves using  different thickness boards. 

###What Is Conway's Game of Life?
The Game of Life is a cellular automation devised by the British mathematician John Horton Conway 。The universe of the Game of Life is an infinite two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, alive or dead. Every cell interacts with its eight neighbors. At each step in time, the following transitions occur:   
1. Any live cell with fewer than two live neighbors die, as if caused by under-population.  
2. Any live cell with two or three live neighbors lives on to the next generation.  
3. Any live cell with more than three live neighbors dies, as if by over-population.  
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.  


###What Is POV?
Persistence of vision refers to the optical illusion whereby multiple discrete images blend into a single image in the human mind and believed to be the explanation for motion perception in cinema and animated films. 


###How We Finish This Project?
To realize an idea of the electrical device, we need to consider both sides from hardware to software. As is known, software can't be tested without hardware platform.   
So we first have to determine the hardware implementation. 
After discussions of many times, we draw a conclusion about the demands of our project:  
- Display specific and pretty patterns to demonstrate the Conway's Game of Life algorithm.
- Spinning Clock with __analog__ display.
- Alternate temperature display on the side view.
- Infra-red communication between a remoter and the device which can be used to change patterns and adjust the time.

We charge the microcontrollers and LED by transfer the electricity from the electric brush of motor .  In this way, the rotating bars can get rid of heavy power source.

We use the MATLAB to simulate the signals of  Conway’s game of life and code LEDs.  And we use C/C++ to realize the  hardware controlling through the Energia.app which is the special programming software of RedBoard MSP 430. The 74hc595 chips are used as input/output shift register to save and translate signals between microcontroller and LEDs.


    
![](https://github.com/jessehui/STM32/blob/master/Misc%20Files/122766282933771898.jpg)
> Here is our project


Conway's game of life will be displayed on the side view:
![](https://github.com/jessehui/STM32/blob/master/Misc%20Files/20160422_084750.jpg)
![](https://github.com/jessehui/STM32/blob/master/Misc%20Files/753126817623064469.jpg)



And Analog clock will be displayed on the top view. However, due to the speed of the motor, we didn't achieve a very good view of the clock because the hour hand which has the smallest radius can't get enough speed to make a good view.  
![](https://github.com/jessehui/STM32/blob/master/Misc%20Files/20160421_190257.jpg)


###Conclusion
Our project creates a virtual cylinder of light using spinning LEDs. The top of this cylinder displays time of day, while the sides display a constantly changing pattern of dots that render a wrap-around version of Conway’s Game of Life. A remote control unit is used to select different Game of Life starting patterns that lead to different results. Our intention was to create something both practical and artistic. 








