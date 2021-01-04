
SRC=$(wildcard *.cc)
EXE=$(SRC:%.cc=%)

.SUFFIXES:
# close the implicit rule

all: ${EXE}
	./s.sh
# build and test it

%: %.o
	g++ -g $< -o $@

%.o: %.cc
	g++ -c $<   

clean:
	rm -f ${EXE} ${EXE}.o
