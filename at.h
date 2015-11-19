#define _AT

extern void ATInit( void ( * )( const char * ), void ( * )( float ) ); //Init AT function pointers

extern void AT( ); //Send AT command to check if everything is OK

extern void ATDialNumber( const char * ); //Call given phone number
