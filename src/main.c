#include <stdio.h>
#include <types.h>
///#include <string.h>
#include <utils.h>

extern char* s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
extern char* s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    
int main(int argc, char** argv){
    u8 val = FALSE;

    for (size_t i = 0; i < 10000000; i++)
    {
        val = streq(s, s1);
    }
    
    return val;
}