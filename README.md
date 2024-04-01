# Pmod STEP Controller
Pmod STEP controller IP and the driver software.

## Usage
This IP is packaged in the similar manner to the following link.

https://digilent.com/reference/learn/programmable-logic/tutorials/pmod-ips/start

## Motor Driving Frequency Setting
On line9 of *PmodSTEP_1.0/hdl/PmodSTEP_v1_0_S00_AXI.v*, the users parameter *MY_FREQ* is set to 666666. It is the variable for translating the input clock frequency of IP core to the driving frequency of the motor. 

On my test environment,

- IP's input clock: 100[MHz]
- Motor's driving frequency: 150[Hz]
- *MY_FREQ* is calculated: 100[MHz]/150[Hz]=666666

Change the value as your system requires.

## Development Environment
- OS: Windows 10
- Vivado and SDK version: 2018.02
- FPGA board: ArtyS7-50
- Stepping motor model number: SPG20-1332
