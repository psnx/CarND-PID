# 1 Files
Please make sure that you use the Updated CMaker file as I added a new file to the project in order to accomodate the twiddler functionality.
Extra files: 
```cpp
CMakeLists.txt
Twiddle.cpp
Twiddle.h
```
I made the empirical tuning of the PID controller by with trial and error and with the help of the included Twiddle class.

# 2 PID Control Reflection
A PID controller may be a good choice when the control specifications are well defined and the magnitude and of disturbances are known:
* The required time for recovery
* Allowable overshoot
* Required stability

The main advantage of this method is its relative simplicity and straight forward applicability in programmable controllers. 
## Components
_Kp - proportional gain_:


```math 
Pout = Kp*e(t)
```
_Ki - integral gain_
Pout = Kp*e(t)


The control is dependent only on the present error term. It represents the _present_ of the control loop. 

The aim is to find a combination of gains which render the vehicles response appropriate, thus avoid overshoots, underdamping and overdamping.







