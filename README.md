# RingPong


### Table of Contents

1. [Preface](#preface)
2. [Quickstart](#quickstart)
3. [Engineering and Design](#design)


## Preface 

#### Tool Stack

#### Platform Compliance

## Quickstart 

## Engineering and Design 

#### Low Battery Indication

The board in question has a red LED which must work at 2Hz and 25% duty cycle. 
Deciding that the average LED pulse width is 1 second and the total signal period is 1 second
a 25% duty cycle would end up being 1/4 the pulse width over a 1 second period. So in 1 second @ 
2Hz the LED would be sent to a high state for two quarter pulse width periods. 


//add diagrams of signal rise time here


