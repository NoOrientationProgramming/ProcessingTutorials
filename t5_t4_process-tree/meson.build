
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
		'../Processing/core_MIT/SystemDebugging.cpp',
		'../Processing/core_MIT/SystemCommanding.cpp',
		'../Processing/core_MIT/TcpListening.cpp',
		'../Processing/core_MIT/TcpTransfering.cpp',
		'../Processing/common_GPLv3/LibTime.cpp',
		'../Processing/common_GPLv3/LibFilesys.cpp',
	],
	include_directories : include_directories([
		'../Processing/core_MIT',
		'../Processing/common_GPLv3',
	]),
)

