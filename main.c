#include <stdio.h>
#define LEN 100
#define YES 1
#define NO 0
int main() {
    char str[LEN];
    char *buf_ptr;
    char *end;
    char *begin;
    char *finder;
    char c;
    char perv_c;
    int flag;
    int found;
    flag = NO;
    found = NO;
    buf_ptr = str;
    perv_c = *buf_ptr;
    begin   = str;
    end     = str;
    finder = str;
    gets(str);
    do
    {
        c = *buf_ptr; // взять текущий символ из буфера
        if( c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
        {
            
            if( flag == YES )
            {
                end = buf_ptr - 1;
                finder = end;
                    if( found == YES )
                    {
                        char *src = end + 1;
                        char *dst = begin;
                        // удаление слова (перенос оставшейся части // строки)
                        while( (*dst++ = *src++ ) != '\0' );
                        buf_ptr = begin;
                    }
            }
            flag = NO;
        }
        else
        {
            if( flag == NO )
                begin = buf_ptr;
            if( perv_c == c )
                found = YES;
            else
                found = NO;
            flag = YES;
        }
        while(1)
        {
            if (*finder == ' ' || *finder == '.' || *finder == ',' || *finder == '\n' || *finder == '\0')
                finder++;
            else
            {
                perv_c = *finder;
                break;
            }
        }
        buf_ptr++;
    }
    while (c!='\0');
    puts(str);
    return 0;
}
