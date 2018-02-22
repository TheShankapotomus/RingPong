
Review the following design specifications for a simple embedded application and write a C program to implement the system. For peripheral interfaces (i.e. GPIO or ADC), use your own API and prototypes. We're not interested in the details of I/O programming here; instead, focus more on the basic system-level architecture, socket programming, and state machine designIf you have any questions or need clarifications on the requirements, please shoot me an email and I'll promptly respond
Please respond with your C code and any other documentation or diagrams detailing your solution to the task.


3.) Network Application
      b.) For every 2-byte UDP packet sent to the server, the server shall return back a 2-byte packet on the same port echoing the counter. If no echo is received within 500ms or the value returned from the server is not equal to the value sent from the device, the device shall re-send the current value. This shall continue until the correct value is received from the server, at which point the device will increment the counter and proceed as normal.
      c.) When the button is released, the socket shall be closed and the counter shall be reset.

### Introduction

problem-solving and coding style.

Review the following design specifications for a simple embedded application and write a C program to implement the system. For peripheral interfaces (i.e. GPIO or ADC), use your own API and prototypes. We're not interested in the details of I/O programming here; instead, focus more on the basic system-level architecture, socket programming, and state machine design.


### System Requirements

#### 1. Embedded Device w/ the following: 

* 1 button (can be pushed and held)
* 1 white LED (controlled via GPIO)
* 1 red LED (controlled via GPIO)
* 1 ethernet inteface (BSD socket capable, IP addressed, Internet accessible)
* 1 battery monitor (interfaced with ADC - millivolt resolution/readings)
* 1 USB battery charger interface (pluggable for charge/discharge of battery)

#### 2. Button Usage

Upon button press the white LED stays lit until button release. 

#### 3. Network Application

a.) While the button is pushed, a UDP socket shall be opened with a server at the domain "test.ring.com" on port 13469. Every 1 second, the device shall send a packet of 2 bytes to the server with a counter, starting at value 0 and increasing by 1 every packet.

b.) For every 2-byte UDP packet sent to the server, the server shall return back a 2-byte packet on the same port echoing the counter. If no echo is received within 500ms or the value returned from the server is not equal to the value sent from the device, the device shall re-send the current value. This shall continue until the correct value is received from the server, at which point the device will increment the counter and proceed as normal. 

c.) When the button is released, the socket shall be closed and the counter shall be reset.

#### 4. Battery Operation

* If the battery voltage is <3.5V the red LED will blink at a 2Hz rate with a 25% duty cycle, and all other functionality will be disabled
* If the battery voltage is >=3.5V the red LED stops blinking and all functionality is enabled

