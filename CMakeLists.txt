cmake_minimum_required(VERSION 3.14)
project(isc205 C)

set(CMAKE_C_STANDARD 99)


add_executable(main lab071/conv_bin_dec/main.c lab071/conv_bin_dec/conversion.c lab071/conv_bin_dec/conversion.h)
