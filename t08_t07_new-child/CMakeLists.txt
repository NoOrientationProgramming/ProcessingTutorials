
cmake_minimum_required(VERSION 2.8.12)
project("NOP - Processing() Tutorials")

include_directories(
	"../ProcessingCore"
)

add_definitions(
	"-DCONFIG_PROC_HAVE_LOG=1"
)

add_executable(
	app
	../ProcessingCore/Processing.cpp
	main.cpp
	Supervising.cpp
	CntSecIncrementing.cpp
	../ProcessingCore/Log.cpp
	../ProcessingCore/SystemDebugging.cpp
	../ProcessingCore/SystemCommanding.cpp
	../ProcessingCore/TcpListening.cpp
	../ProcessingCore/TcpTransfering.cpp
)

if (WIN32)
	add_definitions(
		"-D_WIN32_WINNT=_WIN32_WINNT_WIN10"
		"-DWINVER=_WIN32_WINNT_WIN10"
	)
	target_link_libraries(
		app
		"ws2_32"
	)
endif()

