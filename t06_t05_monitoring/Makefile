
cx=g++
flagsCxx= \
	-I../ProcessingCore \
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

nameApp=app
ifeq ($(OS),Windows_NT)
	nameApp+=.exe
endif

all: $(obs)
	$(cx) -o $(nameApp) $(obs)

%.o: %.cpp
	$(cx) $(flagsCxx) -c $< -o $@

%.o: ../ProcessingCore/%.cpp
	$(cx) $(flagsCxx) -c $< -o $@

clean:
	rm -f ./*.o $(nameApp)

