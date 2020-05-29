cmake_minimum_required(VERSION 3.16)
project(encryption_3des)

set(CMAKE_CXX_STANDARD 14)

add_executable(encryption_3des main.cpp src/Sequence.cpp src/Sequence.h src/SequenceD.cpp src/SequenceD.h)