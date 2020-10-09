OBJ=1.o 2.o 3.o 4.o 5.o
EXE=${OBJ:.o=}
SRC=${OBJ:.o=.cpp}

.SUFFIXES:

all: ${OBJ}

%.o: %.cpp
	g++ -g -c $< 
	g++ -g -o $* $@

clean:
	@rm -f *.o ${EXE}

.PHONY: all clear

#all: ${EXE}

#%: %.cpp
#	g++ -g -c $< 
#	g++ -g -o $@ $<

