# PID controller

PID controller is the way to steer controlled process according to desired outcome and reduce (correct) error. 
 
Examples of such processes can be: movement of objects around trajectory using actuators. Error in this case can be difference 
 between actual and desired locations and speed. Another example is temperature control of environment using heaters, 
 coolers and natural conditions.
  
Basic idea is to use actuators to compensate total error, that consists of 3 parts:
 1. Proportional - difference between actual and desired positions multiplied by Proportional coefficient.
 2. Derivative - difference between errors on current and previous step(s). It prevents process from sharp, high-frequency changes, works like low pass filter. 
 It also helps with stability of the process, by introduction of inertia into control.
 3. Integral - sum of errors of the system over the time. It helps compensate for constant low frequency system noise and adjust bias.
  
How I calculate parameters:
1. All gains initialized to 0. Car drives straight.
2. P coefficient was increased multiple times until it car start follow turns, but system became unstable i.e. car position oscillates
3. D coefficient was incremented until oscillations are suppressed and car follows trajectory
4. I coefficient does not contributed. Seems like emulator does not contribute error into process and over time error biased around zero
5. P and D coefficients were adjusted a couple times to achieve smooth movements and trajectory

What I can do better:
I did not use twiddle or similar method of total error reduction, due to lack of API to control emulator. But in case if
 it would be ability to reset simulator, I would be easy to compute error for one lap and optimize parameters. 
 
I have feeling that for vehicles, we have to prevent overshooting. In real world overshooting can be dangerous in situations 
like changing lines. So, total error for parameter optimization can penalize overshooting.   
 