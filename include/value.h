#pragma once
#include <types.h>
#include <function.h>
#include <object.h>

union value {
    u64 unsigned_integer;
    
    i64 signed_integer;

    f64 floating_point;

    ptr pointer;

    object_t* object;

    struct function* function;
};

typedef union value value_t;