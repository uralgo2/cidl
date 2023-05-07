#include <function.h>
#include <types.h>
#include <memory.h>
#include <malloc.h>
#include <string.h>

void add_function(functions_t* functions, function_t function)
{
    if(IS_NOT_NULL(get_function_by_name(functions, function.name)))
        return;

    if(functions->count + 1 >= functions->capacity){
        functions->capacity *= 2;

        function_t* tmp = (function_t*)malloc(sizeof(function_t) * functions->capacity);

        memcpy((void*)tmp, (void*)functions->functions, sizeof(function_t) * functions->count);

        free((void*)functions->functions);

        functions->functions = tmp;
    }

    functions->functions[functions->count] = function;
    functions->count += 1;
}

function_t* get_function_by_id(functions_t* functions, u64 id)
{
    if(id < functions->count) return (functions->functions + id);

    return NULL;
}

function_t* get_function_by_name(functions_t* functions, char* name)
{
    for (u64 i = 0; i < functions->count; i++)
    {
        if(strcmp(name, (functions->functions + i)->name) == 0)
        return (functions->functions + i);
    }
    
    return NULL;
}
