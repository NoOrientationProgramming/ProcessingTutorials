
project(
	'NOP - Processing() Tutorials',
	'cpp',
)

myApp = executable(
	'app',
	[
		'../Processing/core_MIT/Processing.cpp',
		'main.cpp',
		'Supervising.cpp',
		'../Processing/core_MIT/Log.cpp',
	],
	include_directories : include_directories([
		'../Processing/core_MIT',
	]),
	cpp_args : [
		'-DCONFIG_PROC_HAVE_LOG=1',
	],
)

