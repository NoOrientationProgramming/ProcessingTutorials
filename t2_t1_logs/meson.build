
project(
	'NOP - Processing() Tutorials',
	'cpp',
)

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
	cpp_args : [
		'-DCONFIG_PROC_HAVE_LOG=1',
	],
)

