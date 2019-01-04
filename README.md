# PmodSTEP Controller
**[Verilog] [C]** PmodSTEP controller IP and the driving C programs. 

## Usage
How to use this package is almost the same as [here](https://reference.digilentinc.com/learn/programmable-logic/tutorials/pmod-ips/start).

## Motor Driving Frequency Setting
On line9 of PmodSTEP_1.0/hdl/PmodSTEP_v1_0_S00_AXI.v, the users parameter **MY_FREQ** is set to 666666.  
It is the variable for translating the operating frequency of the board to the driving frequency of the motor.  
On my test environment, the board freq is 100[MHz] and the motor freq is 150[Hz].  
So **MY_FREQ** is calculated as: 100[MHz]/150[Hz]=666666.  
Please change the value according to your target environment.  

## Confirmed Environment
OS: Windows 10  
Vivado and SDK: 2018.02   
FPGA board: ArtyS7-50  
Stepping motor: SPG20-1332
