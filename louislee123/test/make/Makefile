#1 .PONOY 用法
#2 make test trget 用法

#3 compile multifile 
#4 compile multifile and include liburary
#5 build and add test 


#4===========================
# $@: 冒號左方所有檔案   
# $^: 冒號右方所有檔案
# $<: 冒號右方第一個檔案
OBJ= main.o func.o
HEADER= ./header/
SRC= ./src/
EXE= run

all: $(EXE)
.PHONY=all

$(EXE): $(OBJ)
	g++ -o $(EXE)  $^ 


%.o: $(SRC)%.cpp
	g++ -c -o $@ -I $(HEADER) $<

clean:
	rm *.o $(EXE)

#3-3=========================
#OBJ:= 1 3 4 5 
#all: $(OBJ)
#
#%: %.cpp
#	g++  -o $@ $<
#	#echo $@ and $<
#
#clean:
#	rm -f *.o
#3-2=========================
#all: 1.o 2.o 3.o 4.o 5.o 1.c 2.c
#.PHONY: all
#
#5.o:
#	echo this is for 5.o
#
#%.o:
#	echo $@

#3===========================
#all: 1.o 2.o
#
#1.o 2.o:
#	echo $@



#2===========================
#1: 1.o
#	g++ -o 1 1.o  #不可直接用1: 接空白行
#1.o:
#
#2.cpp:
#	echo this is 2.cpp
#
#clean:
#	rm -f 1 1.o
#
#test:
#	./1

#1===========================
#OBJ;=1.cpp 2.cpp 3.cpp
#
#some_File:
#	echo %.c	
#	touch some_File


#.PHONY: clean  #即使"clean"檔存在 仍然執行
#clean:
#	touch clean


