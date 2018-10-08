#include <stdio.h>
#define gets(s) fgets((s),sizeof(s),stdin)
#define YES 1
#define NO 0

int main(void)
{
    char buffer[1000];
    char *bufferPtr;
    char *startPtr;
    char *ptr;
    int found;
    
    gets( buffer );
    bufferPtr = buffer;
    ptr = buffer;
    found = NO;
    
    do
    {
        if ( *bufferPtr == ' ' )
        {
            if (!found)
            {
                found = YES;
                ptr = bufferPtr;
            }
        }
        else
        {
            if (found)
            {
                ptr = ( *bufferPtr == ',' || *bufferPtr == '.' || *bufferPtr == '?' || *bufferPtr == '!' || ptr == buffer) ? ptr : ++ptr;
                startPtr = ptr;
                while ( *ptr++ = *bufferPtr++ );
                found = NO;
                bufferPtr = startPtr;
            }
        }
        bufferPtr++;
    } while( *bufferPtr );
    
    puts( buffer );
    getchar();
    return 0;
}
