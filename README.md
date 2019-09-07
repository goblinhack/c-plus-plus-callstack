C++ program tracing tool
========================

Uses a constructor to maintain a callstack that can be dumped at any time.

This is a portable approach that does not rely on backtrace() and c++ 
demangling which is very unportable.

The only change you need is to include callstack.h and add an underscore
at the beginning of a function (a bit of sedding can do this - reach out 
to me if you cannot do this).

<pre>
        void my_function (void)
        {_
          // rest of code
        }
</pre>

you can even trace inside functions

<pre>
        void my_function (void)
        {_
          // rest of code
         _
          // more code
         _
        }
</pre>

Call the following anytime to dump the current stack:

<pre>
    CALLSTACK_DUMP();
</pre>

To build:

<pre>
    make
    ./callstack 
</pre>

Example output:

<pre>
Stack dump:
(stack) 1 main.cpp void foo3(int, int), line 7
(stack) 2 main.cpp void foo2(int), line 12
(stack) 3 main.cpp void foo1(), line 17
(stack) 4 main.cpp int main(int32_t, char **), line 22
</pre>

NOTE: It should be thread safe as thread local storage is maintained for the callstack.
