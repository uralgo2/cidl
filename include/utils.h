#pragma once 

#include <types.h>
#include <string.h>

u64 mstrlen(char* s) {
    u64 len = 0;
    for (;;) {
        u32 x = *(u32*)s;
        if ((x & 0xFF) == 0) return len;
        if ((x & 0xFF00) == 0) return len + 1;
        if ((x & 0xFF0000) == 0) return len + 2;
        if ((x & 0xFF000000) == 0) return len + 3;
        s += 4, len += 4;
    }
};
u8 streq(char* s1, char* s2) {
    //if(strlen(s1) != strlen(s2)) return FALSE;

    return strcmp(s1, s2) == 0;
};