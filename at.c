#define _AT_C

#include <stdio.h>
#include "at.h"
#define AT_DELAY 1000

void ( *ATOutputFunction )( const char * );
void ( *ATDelayFunction )( float );

char ATBuffer[24];

void ATInit( void ( *ATOutputFunc )( const char * ), void ( *ATDelayFunc )( float ) ) //Init AT function pointers
{
    ATOutputFunction = ATOutputFunc;
    ATDelayFunction = ATDelayFunc;
}


void AT( ) //Send AT command to check if everything is OK
{
    ( *ATOutputFunction )( "AT" );
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( AT_DELAY );
}

void ATDialNumber( const char *Number ) //Call given phone number
{
    sprintf( ATBuffer, "ATD%s;", Number ); //Concatenate phone number with command
    ( *ATOutputFunction )( ATBuffer );
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( AT_DELAY );
}

void ATSendSMS( const char *Number, const char *Text )
{
    ( *ATOutputFunction )( "AT+CMGF=1" ); //Init sending SMS message
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( AT_DELAY );

    sprintf( ATBuffer, "AT+CMGS=\"%s\"", Number ); //Concatenate phone number with command
    ( *ATOutputFunction )( ATBuffer );
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( AT_DELAY );

    ( *ATOutputFunction )( Text ); //Output message text
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( AT_DELAY );

    sprintf( ATBuffer, "%c", 0x1d ); //Create Ctrl+Z escape code to end transmission
    ( *ATOutputFunction )( ATBuffer );
    if( ATDelayFunction != 0 ) ( *ATDelayFunction )( AT_DELAY );
}
