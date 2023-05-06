# ProcessingTutorials <!-- omit in toc -->

Learn how to use the [Processing()](https://github.com/NoOrientationProgramming/ProcessingCore) class.

## Run the Tutorials

### Install the required Build Tools

On Debian, Ubuntu and derivatives execute the following with root permissions

`apt install build-essential`

If you want to use [meson and ninja](https://mesonbuild.com/) (recommended) add

`apt install meson ninja-build`

### Clone the tutorial repository

`git clone https://github.com/NoOrientationProgramming/ProcessingTutorials.git`

### Initialize and Update the Submodules

Enter the new directory with `cd ProcessingTutorials/` and execute

`git submodule update --init --recursive`

### Build and Run a Tutorial

Enter a tutorial directory. For example `cd t1_hello-world/`

Build the application with

`meson build && ninja -C build`

Then execute the application by entering

`./build/app`

### Read the documentation

Every tutorial will have its own README file for further information explaining what is going on.

## Add the Processing() class to your project

If you want to use the core in your own project then simply add the repository as a submodule like this

`git submodule add https://github.com/NoOrientationProgramming/ProcessingCore.git`
