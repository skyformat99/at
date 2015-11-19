#define _AT_C

#include <stdio.h>
#include "at.h"

#ifndef AT_BUFFER_SIZE
#define AT_BUFFER_SIZE 32
#endif

void ( *ATOutputFunction )( const char * );
void ( *ATDelayFunction )( double );

char ATBuffer[AT_BUFFER_SIZE];

double ATDelay;

void ATInit( void ( *ATOutputFunc )( const char * ), void ( *ATDelayFunc )( double ), double DelayTime ) //Init AT function pointers
{
    ATOutputFunction = ATOutputFunc;
    ATDelayFunction = ATDelayFunc;
    ATDelay = DelayTime;
}


////Dialing functions//

void ATDialNumber( const char *Number ) //Call given phone number
{
    sprintf( ATBuffer, "ATD%s;", Number ); //Concatenate phone number with command
    ( *ATOutputFunction )( ATBuffer );
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( ATDelay );
}

void ATAcceptCall( ) //Accept incoming call
{
    ( *ATOutputFunction )( "ATA" );
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( ATDelay );
}

void ATRejectCall( ) //Reject incoming call
{
    ( *ATOutputFunction )( "ATH" );
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( ATDelay );
}

////SMS functions////

void ATSendSMS( const char *Number, const char *Text ) //Send given text to given phone number
{
    ( *ATOutputFunction )( "AT+CMGF=1" ); //Init sending SMS message
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( ATDelay );

    sprintf( ATBuffer, "AT+CMGS=\"%s\"", Number ); //Concatenate phone number with command
    ( *ATOutputFunction )( ATBuffer );
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( ATDelay );

    ( *ATOutputFunction )( Text ); //Output message text
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( ATDelay );

    sprintf( ATBuffer, "%c", 26 ); //Create Ctrl+Z escape code to end transmission
    ( *ATOutputFunction )( ATBuffer );
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( ATDelay );
}

////Other functions////

void AT( ) //Send AT command to check if everything is OK
{
    ( *ATOutputFunction )( "AT" );
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( ATDelay );
}

void ATSignalQuality( )
{
    ( *ATOutputFunction )( "AT+CSQ" );
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( ATDelay );
}
