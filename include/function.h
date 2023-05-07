#pragma once 

#include <types.h>
#include <frame.h>

enum FUNCTION_FLAGS {
    FUNCTION_FLAG_VOID_RETURN = 1,
    FUNCTION_FLAG_NATIVE = 2,
    FUNCTION_FLAG_CLOSURE = 4,
    FUNCTION_VARARGS = 8
};

struct function {
    ptr pointer; 
    u32 argc;
    u32 locals;
    u32 max_stack;
    frame_t* catched_frame; // closure only, in regular function is null(0)
    u8 flags;
    char* name;
};

struct return_addr {
    struct function* fn;
    u64 offset;
};

struct functions
{
    u64 count, capacity;
    struct function* functions;
};

void add_function(struct functions*, struct function);
struct function* get_function_by_id(struct functions*, u64 id);
struct function* get_function_by_name(struct functions*, char* name);

typedef struct functions functions_t;

typedef struct return_addr return_addr_t;

typedef struct function function_t;