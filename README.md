# RingPong


### Table of Contents

1. [Preface](#preface)
2. [Build and Test](#build)
3. [Engineering and Design](#design)


## Preface <a name="preface"></a>

This project was designed with Clang on OS X and the application 
was tested standalone in a terminal environment. The dev requirements for this project can be
found in the CHALLENGE.MD file under the root of this project.

#### Tool Stack

This project uses:

- [C99](http://www.iso-9899.info/wiki/The_Standard) - 1999 C Standard

#### Platform Compliance

This project has been compiled and tested on:

- Mac OS X
    - Compiler: Apple LLVM version 8.0.0 (clang-800.0.38)
    - Requires: Xcode CLI toolset
- CentOS 7 
    - Compiler: GCC 4.8.5 20150623 (Red Hat 4.8.5-16)
    - Requires: "Development Tools" and libnetd

#### Application Help

```bash
usage: ./ring-pong [button state] [current voltage]
button state is either 1 or 0, current voltage is 0.0 - 5.0 volts

----
example usage: ./ring-pong 1 3.5
```

## Build and Test <a name="build"></a>

After cloning the project, go into the base directory and create two subdirectories.
```bash
cd ./RingPong
mkdir bin obj

```

Following this, a simple ___make___ call should compile and drop the binary into the _./RingPong/bin_ folder

```bash
make #build the binary

make clean #remove the object files

make remove #remove the binary and object files 
```

The __Makefile__ was originally hand-rolled from simple commands, but for better project management 
an [open-source example](https://stackoverflow.com/questions/7004702/how-can-i-create-a-makefile-for-c-projects-with-src-obj-and-bin-subdirectories)
 was used that allowed for a refined directory structure.
 
#### Testing 

The _stdout_ is verbose in terms of logging the actions that happen; quickly the 
red LED flashing and the udp_server sending/receiving flood the terminal with output. Be sure
to look at the top few messages to see the state of all the peripherals.

```bash
./ring-pong 1 3.5 #simulates button press, and 3.5V battery charge

```

```bash
./ring-pong 1 2.7 #simulates button press, and 2.7V battery charge
```

```bash
./ring-pong 0 4.5 #simulates no button press, and 4.5V battery charge
```

```bash
./ring-pong 0 1.3 #simulates no button press, and 1.3V battery charge 
```

## Engineering and Design <a name="design"></a>

#### Project Layout

File: hw_setup.c/.h

-   Contains all hardware setup functionality for interfacing with the various peripherals and modifying their states

File: udp_server.c/.h
    
-   Is the UDP server implementation; it uses a few global variables so that minimal state can be held while allowing
control of sending and receiving to be handled outside the scope of the file directly. An educational reference for this 
development can be found at this [Rutger's tutorial](https://www.cs.rutgers.edu/~pxk/417/notes/sockets/udp.html); the 
man pages for [recvfrom](https://linux.die.net/man/2/recvfrom) and [sendto](https://linux.die.net/man/2/sendto) were also
used.

File: main.c

- Imploys the CLI interface and main handling of the system logic. If it were implemented on a real
embedded system, a loop that waits for a system signal would need to be employed around the main logic (the location of which
is marked in _main.c_). As such, testing is limited to the states that one can change through the CLI and dynamic change 
in system state is currently not possible. 

#### ADC Implementation

The determined resolution (as it was not explicitly stated) for the ADC was 12-bit or ( 2<sup>12</sup> - 1 ).
Using calculations found at [sparkfun.com](https://learn.sparkfun.com/tutorials/analog-to-digital-conversion) for ADC 
measurments with millivolt system voltage reference (assumed to be 3.5V as that's when board functionality cuts off)
made the equation come out to 
   ```
   (4095/3500 mV) * V * 1000 = Current Voltage Level
   ```
   
   Where _V_ is the voltage read in from the ADC and in the program from the second command line parameter.

#### Low Battery Indication

The embedded system has a red LED which must work at 2Hz and 25% duty cycle. 
With the average LED pulse width and the total signal period both at 1 second,
a 25% duty cycle would end up being 1/4 the pulse width over a 1 second period. So in 1 second @ 
2Hz the LED would be sent to a high state for two quarter pulse width periods. These are the sources for 
[duty cycle](https://en.wikipedia.org/wiki/Duty_cycle) and [Hertz](https://en.wikipedia.org/wiki/Hertz) research.


