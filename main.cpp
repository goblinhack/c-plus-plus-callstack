
#define __MAIN__
#include "callstack.h"

void foo3 (void)
{ LOG_CALL
    global_callstack.dump();
}

void foo2 (void)
{ LOG_CALL
    foo3();
}

void foo1 (void)
{ LOG_CALL
    foo2();
}

int main (int32_t argc, char *argv[])
{ LOG_CALL
    foo1();
    return (0);
}
