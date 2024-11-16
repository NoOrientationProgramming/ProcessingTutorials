
![GitHub](https://img.shields.io/github/license/NoOrientationProgramming/ProcessingTutorials?style=plastic)
![Twitch Status](https://img.shields.io/twitch/status/Naegolus?label=twitch.tv%2FNaegolus&logo=Twitch&logoColor=%2300ff00&style=plastic)

Learn how to use the [Processing()](https://github.com/NoOrientationProgramming/ProcessingCore) class.

&rarr; Streaming every Tuesday and Thursday at 20:00 (8 PM) CEST at [twitch.tv/Naegolus](https://twitch.tv/Naegolus)

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
  - Running on Windows, Linux & Raspberry Pi
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
`./meson.sh t01_hello-world`
or just
`./meson.sh t01`

Then execute the application by entering

`./t1_hello-world/build-meson-ubuntu/app`

## Read the documentation

Every tutorial will have its own README file for further information explaining what is going on.

## Add the Processing() class to your project

If you want to use the core in your own project then simply add the repository as a submodule like this

`git submodule add https://github.com/NoOrientationProgramming/ProcessingCore.git`
