
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

cxx = meson.get_compiler('cpp')

deps = []
deps += dependency('threads')

args = []
args += '-DCONFIG_PROC_HAVE_LOG=1'
args += '-std=gnu++11'

if host_machine.system() == 'windows'
	args += '-D_WIN32_WINNT=_WIN32_WINNT_WIN10'
	args += '-DWINVER=_WIN32_WINNT_WIN10'
	deps += cxx.find_library('ws2_32')
endif

myApp = executable(
	'app',
	[
		'../ProcessingCore/Processing.cpp',
		'main.cpp',
		'Supervising.cpp',
		'../ProcessingCore/Log.cpp',
		'../ProcessingCore/SystemDebugging.cpp',
		'../ProcessingCore/SystemCommanding.cpp',
		'../ProcessingCore/TcpListening.cpp',
		'../ProcessingCore/TcpTransfering.cpp',
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

