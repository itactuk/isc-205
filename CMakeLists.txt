cmake_minimum_required(VERSION 3.14)
project(isc205 C)

set(CMAKE_C_STANDARD 99)


add_executable(main_conv_bin_dec lab071/conv_bin_dec/main_conv_bin_dec.c lab071/conv_bin_dec/conversion.c lab071/conv_bin_dec/conversion.h)

add_executable(main_productopunto lab071/productopunto/main_productopunto.c lab071/productopunto/productopunto.c lab071/productopunto/productopunto.h)