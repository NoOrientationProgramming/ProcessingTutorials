
cx=g++
flagsCxx= \
	-I../Processing/core_MIT \
	-DCONFIG_PROC_HAVE_LOG=1 \

obs= \
	Processing.o \
	main.o \
	Supervising.o \
	Log.o \

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

clean:
	rm -f ./*.o $(nameApp)

