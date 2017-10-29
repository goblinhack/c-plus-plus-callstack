
#define __CALLSTACK_MAIN__ // define this in one file only

#include "callstack.h" // include this in all files

void foo3 (int also_unused, int and_so_is_this)
{_
    CALLSTACK_DUMP();
}

void foo2 (int unused)
{_
    foo3(0, 1);
}

void foo1 (void)
{_
    foo2(0);
}

int main (int32_t argc, char *argv[])
{_
    foo1();
    return (0);
}
