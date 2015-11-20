# What is AT library?
AT is library for simplifying use of **AT** commands in **C** language.
<br>
All You need to do is to redirect its output to serial port or **UART** and set few other things.
<br><br>
Every call of **C** function is translated to **AT** commands, so You can do everything very easily.
<br>
For example, sending **SMS** takes only one call!

**Note: This library does NOT support reading input yet, so You have to interpret incoming responses Yourself.**

# Features
 - Dialing 
 - Call accepting or rejecting
 - Sending **SMS**
 - Reading **SMS** *(but not interpreting response)*
 - Switching between PDU and text mode
 - Checking signal quality
 - *Many more incoming*

# How to use it?
This is very basic code for testing AT library. Everything should be clear.
```c
#include <stdio.h>
#include <unistd.h>

#include "AT/at.h"

void Sleep( double Usec )
{
    usleep( (useconds_t)( Usec * 1000000.0 ) );
}

int main( )
{
    //For test purposes, redirect output to "printf"
    ATInit( &printf, &Sleep, 0.25 ); //Init AT library

    AT( ); //Request AT
    printf( "\n" ); //New line

    ATDialNumber( "55750818" ); //Dial number
    printf( "\n" ); //New line

    ATSendSMS( "555750818", "Hi John!" ); //Send text
    printf( "\n" ); //New line

    ATAcceptCall( ); //Accept incoming call
    printf( "\n" ); //New line

    ATRejectCall( ); //Reject incoming call
    printf( "\n" ); //New line

    return 0;
}

```
