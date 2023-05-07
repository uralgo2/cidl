#pragma once

#include <types.h>
#include <value.h>

struct frame {
    u32 locals_count;
    value_t* locals;
    struct frame* parent;
};

typedef struct frame frame_t;