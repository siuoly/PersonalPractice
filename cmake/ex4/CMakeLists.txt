cmake_minimum_required(VERSION 3.16)
project(Myproject VERSION 1.0.0)
add_executable(hello hello.c f1.c )
target_link_libraries(hello ncurses pthread)

