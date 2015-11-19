#define _AT

//Main//
extern void ATInit( void ( * )( const char * ), void ( * )( double ), double ); //Init AT function pointers

//Dial//
extern void ATDialNumber( const char * ); //Call given phone number
extern void ATAcceptCall( ); //Accept incoming call
extern void ATRejectCall( ); //Reject incoming call

//SMS//
extern void ATSendSMS( const char *, const char * ); //Send given text to given phone number

//Other//
extern void AT( ); //Send AT command to check if everything is OK
