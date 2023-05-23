
project(
	'NOP - Processing() Tutorials',
	'cpp',
)

cxx = meson.get_compiler('cpp')

args = []
deps = []

#args += '-DCONFIG_PROC_HAVE_LOG=1'
deps += dependency('threads')

if host_machine.system() == 'windows'
	args += '-D_WIN32_WINNT=_WIN32_WINNT_WIN10'
	args += '-DWINVER=_WIN32_WINNT_WIN10'
	deps += cxx.find_library('ws2_32')
endif

args += [
	'-Wall',
	'-Wextra',
	'-Wpedantic',
	'-Werror',
	'-Wfatal-errors',
	'-Wreorder',
	'-Wswitch-enum',
	'-Wuseless-cast',
	'-Wparentheses',
	'-Wshift-overflow',
	'-Wsign-compare',
	'-Wzero-as-null-pointer-constant',
	'-Wcast-align',
	'-Wcast-qual',
	'-Wcatch-value',
	'-Wchar-subscripts',
	'-Wswitch-default',
	'-Wctor-dtor-privacy',
	'-Wduplicated-branches',
	'-Wduplicated-cond',
	'-Wempty-body',
	'-Wextra-semi',
	'-Wfloat-equal',
	'-Wformat',
	'-Wformat-extra-args',
	'-Wimplicit-fallthrough',
	'-Wmissing-field-initializers',
	'-Wnull-dereference',
	'-Wshadow',
]

args += [
	'-DCONFIG_PROC_HAVE_DRIVERS=0',
	'-DCONFIG_PROC_HAVE_GLOBAL_DESTRUCTORS=1',
	'-DCONFIG_PROC_USE_STD_LISTS=0',
	'-DCONFIG_PROC_USE_DRIVER_COLOR=1',
	'-DCONFIG_PROC_HAVE_LOG=1',
	'-DCONFIG_PROC_SHOW_ADDRESS_IN_ID=1',
	'-DCONFIG_PROC_DISABLE_TREE_DEFAULT=0',
]

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

