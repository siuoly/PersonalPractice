cmake_minimum_required( VERSION 3.16.3)

project( net )
add_executable(cli cli.cc)
add_executable(ser ser.cc)

add_library(my cli.cc ser.cc)

