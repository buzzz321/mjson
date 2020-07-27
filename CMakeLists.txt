# CMakeList.txt : CMake project for mjson, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("mjson")

# Add source to this project's executable.
add_executable (mjson "mjson.cpp" "mjson.h" "parser.h" "parser.cpp")

# TODO: Add tests and install targets if needed.
