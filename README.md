C++ program tracing tool

Uses a constructor to maintain a callstack that can be dumped at any time.

This is a portable approach that does not rely on backtrace() and c++ 
demangling which is very unportable.

The only change you need is to include callstack.h and add _ at the beginning
of a function (a bit of sedding can do this - reach out to me if you cannot 
do this).

e.g.:
        void my_function (void)
        { LOG_CALL
          // rest of code
        }


Just do 

  make
  ./callstack 

  Stack dump:
  (stack) 1 main.cpp void foo3(), line 6
  (stack) 2 main.cpp void foo2(), line 11
  (stack) 3 main.cpp void foo1(), line 16
  (stack) 4 main.cpp int main(int32_t, char **), line 21

