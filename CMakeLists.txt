cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 17)

# Set the project name
project(spreadsheet CXX)

# Set the directory for the executable
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

# Set the directory for the test executables
set(TEST_EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/test")

# Add library
add_library(sh_lib 
    spreadsheetcell.cpp 
    spreadsheet.cpp)

# Add the source files for the main program
set(SOURCES
 main.cpp
)

# Add the test files
set(TEST_SOURCES
  test/spreadsheet_tests.cpp
)

# Find ncurses library and include
# Find_package(Curses REQUIRED)
# include_directories(${CURSES_INCLUDE_DIR})

# Find the Boost library and include the Boost test framework
 find_package(Boost REQUIRED COMPONENTS unit_test_framework)
 include_directories(${Boost_INCLUDE_DIRS})

# 

# Add the executable for the main program
add_executable(spreadsheet ${SOURCES})
target_link_libraries(spreadsheet sh_lib ${CURSES_LIBRARIES})

# Enable testing with CTest
enable_testing()

# Add the test executables
foreach(test_src ${TEST_SOURCES})
  get_filename_component(test_name ${test_src} NAME_WE)
  add_executable(${test_name} ${test_src})
  target_link_libraries(${test_name} sh_lib ${Boost_LIBRARIES})
  add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
