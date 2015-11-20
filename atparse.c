#define _AT_PARSE_C

#include <stdio.h>
#include <string.h>

#include "atparse.h"

char *ATParseSMS( char *Input ) //Parse AT output after using of ATReadSMS( ) function
{
    int Length = strlen( Input );
    int i = 0, j = 0, Begin = 0, End = 0;

    for ( i = 0; i < Length - 5; i++ )
        if ( Input[i] == '+' && Input[i + 1] == 'C' && Input[i + 2] == 'M' && Input[i + 3] == 'G' && Input[i + 4] == 'R' && Input[i + 5] == ':' )
        {
            for ( j = i; j < Length; j++ )
                if ( Input[j] == 10 )
                {
                    Begin = j + 1;
                    break;
                }
        }

    for ( i = Begin; i < Length - 3; i++ )
    {
        if ( Input[i] == '\n' && Input[i + 1] == '\n' && Input[i + 2] == 'O' && Input[i + 3] == 'K' )
        {
            End = i - 1;
        }
    }

    //printf( "\n%d(%c), %d(%c)\n", Begin, Input[Begin], End, Input[End] );

    Input[End + 1] = 0;

    return &Input[Begin];
}
