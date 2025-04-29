
project('NOP - Tutorials', 'cpp')

myApp = executable(
	'app',
	[
		'../SystemCore/Processing.cpp',
		'../SystemCore/Log.cpp',
		'../SystemCore/TcpListening.cpp',
		'../SystemCore/TcpTransfering.cpp',
		'../SystemCore/SystemCommanding.cpp',
		'../SystemCore/SystemDebugging.cpp',
		'main.cpp',
		'Supervising.cpp',
		'UserInteracting.cpp',
	],
	include_directories : include_directories([
		'../SystemCore',
	]),
	dependencies : [
		dependency('threads'),
	],
	cpp_args : [
		'-std=gnu++11',
		'-DCONFIG_PROC_HAVE_LOG=1',
	],
)

