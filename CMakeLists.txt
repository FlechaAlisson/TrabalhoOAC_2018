cmake_minimum_required(VERSION 3.10)
project(TrabOAC)

set(CMAKE_CXX_STANDARD 11)

add_executable(TrabOAC main.cpp cmake-build-debug/Model/BancoReg.cpp cmake-build-debug/Model/BancoReg.h cmake-build-debug/Model/RAM.cpp cmake-build-debug/Model/RAM.h cmake-build-debug/Model/UnidadeControle.cpp cmake-build-debug/Model/UnidadeControle.h)