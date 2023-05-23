
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
	../ProcessingCore/Log.cpp
)

