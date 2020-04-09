cmake_minimum_required(VERSION 3.15)
project(AP_Hw3)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP_Hw3 main.cpp Matrix.cpp Matrix.h Dataset.cpp Dataset.h aphw3.cpp aphw3.h NeuralNet.cpp NeuralNet.h Result.cpp Result.h)