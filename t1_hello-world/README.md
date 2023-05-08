
## Files

- Makefile & meson.build
- main.cpp
- Supervising.h
- Supervising.cpp

## Makefile & meson.build

These files define how to build the application. We will not discuss them here. More information about the files can be found at
- [The Meson Build system](https://mesonbuild.com/)
- [GNU make](https://www.gnu.org/software/make/manual/make.html)

We would recommend to use meson because it's a new easy-to-use build system. You can also use others like CMake, autotools or others of course.

## main.cpp

You should be familiar with the function `main()`. This is the entry point of your application and must be available to the linker somewhere in your application. The function is usually located in a file called `main.cpp` like here. We will go through this file line by line. On top we have all necessary includes. The first two
```
#include <iostream>
#include <thread>
```
should be known already. `iostream` gives access to the standard output streams `cout` and `cerr`. The second one `thread` is used to sleep some time in the main loop which is running in the main thread.

The next line
```
#include "Supervising.h"
```
gives you access to the top-level (root) process of your application. This process is called `Supervising()` in our case. The name is chosen because in most cases this process is used to encapsulate the `SystemDebugging()` process as well as the actual high-level process of the application which is containing all of your business logic. You can call the process as you like of course. There is only one thing we would strongly recommend: The end of the process name should be a verb in present participle (ing-form)

