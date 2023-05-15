
cx=g++
flagsCxx= \
	-I../ProcessingCore \

obs= \
	Processing.o \
	main.o \
	Supervising.o \

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

