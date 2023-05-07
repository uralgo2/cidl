#pragma once

#include <types.h>

struct object {
    u32 type_id, rc;
    // some binary content
};

typedef struct object object_t;