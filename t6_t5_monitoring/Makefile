
cx=g++
flagsCxx= \
	-I../Processing/core_MIT \
	-I../Processing/common_GPLv3 \
	-DCONFIG_PROC_HAVE_LOG=1 \

obs= \
	Processing.o \
	main.o \
	Supervising.o \
	Log.o \
	SystemDebugging.o \
	SystemCommanding.o \
	TcpListening.o \
	TcpTransfering.o \
	LibTime.o \
	LibFilesys.o \

nameApp=app
ifeq ($(OS),Windows_NT)
	nameApp+=.exe
endif

all: $(obs)
	$(cx) -o $(nameApp) $(obs)

%.o: %.cpp
	$(cx) $(flagsCxx) -c $< -o $@

%.o: ../Processing/core_MIT/%.cpp
	$(cx) $(flagsCxx) -c $< -o $@

%.o: ../Processing/common_GPLv3/%.cpp
	$(cx) $(flagsCxx) -c $< -o $@

clean:
	rm -f ./*.o $(nameApp)

