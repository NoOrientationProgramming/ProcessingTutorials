
project('NOP - Processing() Tutorials', 'cpp')

myApp = executable(
	'app',
	[
		'../ProcessingCore/Processing.cpp',
		'../ProcessingCore/Log.cpp',
		'../ProcessingCore/TcpListening.cpp',
		'../ProcessingCore/TcpTransfering.cpp',
		'../ProcessingCore/SystemCommanding.cpp',
		'../ProcessingCore/SystemDebugging.cpp',
		'main.cpp',
		'Supervising.cpp',
		'UserInteracting.cpp',
	],
	include_directories : include_directories([
		'../ProcessingCore',
	]),
	dependencies : [
		dependency('threads'),
	],
	cpp_args : [
		'-std=gnu++11',
		'-DCONFIG_PROC_HAVE_LOG=1',
	],
)

