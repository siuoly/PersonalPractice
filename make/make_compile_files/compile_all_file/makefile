# 一次編譯目錄下所有檔案
EXE=$(patsubst %.cpp,%,$(wildcard *.cpp))
#或者用 EXE=$(SRC:
all: ${EXE}

clean:
	@rm -f ${EXE}
