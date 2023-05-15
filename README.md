# ProcessingTutorials <!-- omit in toc -->

Learn how to use the [Processing()](https://github.com/NoOrientationProgramming/ProcessingCore) class.

## Status of the project

### Processing()

- Mature code created in 2018
- Finished

### ProcessingTutorials

- In progress
- Goal
  - Approx. 10 short applications
  - Only containing usage of the Processing() class
  - No other dependencies
  - Running on Windows / Linux (Desktop + R-Pi)
  - README for every tutorial
- Finished to: 30%

## Run the Tutorials

### Install the required Build Tools

On Debian, Ubuntu and derivatives execute the following with root permissions

`apt install build-essential`

If you want to use [meson and ninja](https://mesonbuild.com/) (recommended) add

`apt install meson ninja-build`

### Clone the tutorial repository

`git clone https://github.com/NoOrientationProgramming/ProcessingTutorials.git`

Initialize and Update the Submodules

Enter the new directory with `cd ProcessingTutorials/` and execute

`git submodule update --init --recursive`

### Build and Run a Tutorial

Type
`./meson.sh t1_hello-world`
or just
`./meson.sh t1`

Then execute the application by entering

`./t1_hello-world/build-meson-ubuntu/app`

### Read the documentation

Every tutorial will have its own README file for further information explaining what is going on.

## Add the Processing() class to your project

If you want to use the core in your own project then simply add the repository as a submodule like this

`git submodule add https://github.com/NoOrientationProgramming/ProcessingCore.git`
