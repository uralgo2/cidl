#pragma once

#include <types.h>
#include <value.h>
#include <function.h>

struct interpreter_state {
    u64 ip, sp, csp;
    value_t* stack;
    return_addr_t* call_stack;

    u8* code;

    functions_t* functions;
};