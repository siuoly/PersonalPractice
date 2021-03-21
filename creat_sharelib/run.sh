gcc -g -fPIC -c f.cc
#-fPIC: when diff process use same lib, put lib in diff memory position.

g++ -shared f.o -o libf.so
# set share lib

g++ main.cc ~/t/creat_sharelib/libf.so -L.
# -L. : search lib in current dir when compile
# nowdir/libf.so: search lib when run program

#method2
# g++ main.cc -lf -L.
# LD_LIBRARY_PATH=. ./a.out  # indicate shared lib position

ldd a.out
# show the link table

./a.out


# reference: Linux 編譯shared library 的方法和注意事項
