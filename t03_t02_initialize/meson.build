
# For Windows do:
# apt install mingw-w64
# update-alternatives --config x86_64-w64-mingw32-g++

# For Raspberry Pi do:
# apt install gcc-arm-linux-gnueabi
# apt install g++-arm-linux-gnueabi

project(
	'NOP - Processing() Tutorials',
	'cpp',
)

deps = []
deps += dependency('threads')

args = []
args += '-DCONFIG_PROC_HAVE_LOG=1'
args += '-std=gnu++11'

myApp = executable(
	'app',
	[
		'../ProcessingCore/Processing.cpp',
		'main.cpp',
		'Supervising.cpp',
		'../ProcessingCore/Log.cpp',
	],
	include_directories : include_directories([
		'../ProcessingCore',
	]),
	dependencies : [
		deps,
	],
	cpp_args : [
		args,
	],
)

