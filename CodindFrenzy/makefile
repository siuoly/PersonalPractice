SRC=$(wildcard *.cpp)
OBJ:= $(SRC:.cpp=.o)
EXE =$(patsubst %.cpp,%,$(wildcard *.cpp))


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

