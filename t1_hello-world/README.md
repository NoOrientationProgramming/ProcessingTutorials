
## Files

- Makefile & meson.build
- main.cpp
- Supervising.h
- Supervising.cpp

## Makefile & meson.build

These files define how to build the application. We will not discuss them here.
More information about the files can be found at
- [The Meson Build system](https://mesonbuild.com/)
- [GNU make](https://www.gnu.org/software/make/manual/make.html)

We would recommend to use meson because it's a new easy-to-use build system.
You can also use others like CMake, autotools or others of course.

## main.cpp

You should be familiar with the function `main()`.
This is the entry point of your application and must be available to the linker somewhere in your application.
The function is usually located in a file called `main.cpp` like here.
We will go through this file line by line.
The main file is almost the same for all projects and can be reused very often.
On top we have all necessary includes. The first two
```cpp
#include <iostream>
#include <thread>
```
should be known already. `iostream` gives access to the standard output streams `cout` and `cerr`.
The second one `thread` is used to sleep some time in the main loop which is running in the main thread.

The next line
```cpp
#include "Supervising.h"
```
gives you access to a C++ class. The class implements the top-level (root) process of your application.
Important: If we say `process` we are not talking about a process (program) which is running on a so-called "Operating System".

At this point we should explain some key concepts and our naming conventions already.
TODO:
- What is a function?
  - Math: y = f(x)
  - Software (Stack)
- What is a process?
  - Math: y = p(x, t)
  - Software (Heap)
- The (abstract) C++ class Processing() implements the general behavior of a process
- All processes are located on the dynamic memory (Heap)
- On Microcontrollers heap is faked

The root process is called `Supervising()` in this tutorial.
The name is chosen because in most cases this process is used to encapsulate the `SystemDebugging()` process as well as
the actual high-level process of the application which is containing all of your business logic.
You can change the name of the process to whatever you like of course.
There is only one thing we would strongly recommend:
The end of the process name should be a verb in present participle (ing-form)

Now we add all namespaces we want to use. In this case we only use `std`
```cpp
using namespace std;
```
This line is optional. You can omit this line if you want. Just remember to write `std::cout` instead of `cout` then.

With the next line
```cpp
Supervising *pApp = NULL;
```
we create a variable which is located in the initialized data section of our program.
This variable will contain the address (pointer) to our root process.
