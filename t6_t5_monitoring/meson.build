
project(
	'NOP - Processing() Tutorials',
	'cpp',
)

cxx = meson.get_compiler('cpp')

args = []
deps = []

args += '-DCONFIG_PROC_HAVE_LOG=1'
deps += dependency('threads')

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
	cpp_args : [args],
	dependencies : [deps],
)

