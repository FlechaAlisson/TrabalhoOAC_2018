cmake_minimum_required(VERSION 3.10)
project(TrabOAC)

set(CMAKE_CXX_STANDARD 11)


add_executable(TrabOAC main.cpp Model/RAM.cpp Model/RAM.h Model/UnidadeControle.cpp Model/UnidadeControle.h Util/Util.cpp Util/Util.h Model/ULA.cpp Model/ULA.h Model/Somador.cpp Model/Somador.h Model/BancoReg.cpp Model/BancoReg.h)