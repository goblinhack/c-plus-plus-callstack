#pragma once
#include <string>
#include <vector>
#include <stdio.h>

#undef _ 
#define _ tracer_t __my_tracer(__FILE__, __PRETTY_FUNCTION__, __LINE__);

struct callframe {
    const char *const file;
    const char *const func;
    unsigned int line;
};

class callstack {
public:
    callstack(void) {}
    ~callstack(void) {}

    void dump(void);

    /*
     * Did not use stack<> as it has no iterators
     * */
    std::vector<struct callframe> my_stack;
};

#ifdef __CALLSTACK_MAIN__
thread_local class callstack global_callstack;
#else
extern thread_local class callstack global_callstack;
#endif

struct tracer_t {
    tracer_t (const char *const file, 
              const char *const func, 
              const unsigned int line) :
              file(file), func(func), line(line)
    {
        callframe c = { file, func, line };

        global_callstack.my_stack.push_back(c);
    }

    ~tracer_t()
    {
        global_callstack.my_stack.pop_back();
    }

    std::string file;
    std::string func;
    unsigned int line;
};

#define CALLSTACK_DUMP global_callstack.dump

void callstack::dump (void) 
{
    int i = 1;

    fprintf(stderr, "Stack dump:\n");
    for (auto iter = my_stack.rbegin(); iter != my_stack.rend(); iter++) {
        fprintf(stderr, "(stack) %d %s %s, line %u\n", i++, iter->file, iter->func, iter->line);
    }
}
