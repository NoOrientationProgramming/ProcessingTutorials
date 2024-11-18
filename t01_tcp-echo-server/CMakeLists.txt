
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
	../ProcessingCore/Log.cpp
	../ProcessingCore/TcpListening.cpp
	../ProcessingCore/TcpTransfering.cpp
	../ProcessingCore/SystemCommanding.cpp
	../ProcessingCore/SystemDebugging.cpp
	main.cpp
	Supervising.cpp
	UserInteracting.cpp
)

