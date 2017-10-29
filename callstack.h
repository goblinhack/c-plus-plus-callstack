#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

/*
 * Convert function and line number into a single string for debugging.
 */
#define CLOG_STRINGIFY(x)   #x
#define CLOG_TO_STRING(x)   CLOG_STRINGIFY(x)

/*
 * __FUNCTION__ is not a preprocessor directive so we can't convert it into a
 * string
 */
#define CLOG_AT  __FILE__, __PRETTY_FUNCTION__, __LINE__

#define LOG_CALL tracer_t __my_tracer(CLOG_AT);

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

    std::vector<struct callframe> my_stack;
};

#ifdef __MAIN__
thread_local class callstack global_callstack;
#else
extern thread_local class callstack global_callstack;
#endif

struct tracer_t {
    tracer_t (const char *const file, const char *const func, const unsigned int line) :
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

void callstack::dump (void) 
{
    int i = 1;

    fprintf(stderr, "Stack dump:\n");
    for (auto iter = my_stack.rbegin(); iter != my_stack.rend(); iter++) {
        fprintf(stderr, "(stack) %d %s %s, line %u\n", i++, iter->file, iter->func, iter->line);
    }
}
