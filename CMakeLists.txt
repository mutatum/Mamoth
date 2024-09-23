cmake_minimum_required(VERSION 3.10)
project(mamoth)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable testing
# enable_testing()

# Find gtest
# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})

# Create a library from your source files
add_library(mamoth SHARED
    src/functional/functional.hpp
    src/functional/functional.cpp
    src/optimization/optimizationalgorithm.hpp
)

# Optionally, specify where to output the library
set_target_properties(mamoth PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
# Include the source directory for the library
# target_include_directories(mamoth PUBLIC src)

# Link the mamoth library and gtest to the test executable
# target_link_libraries(mamoth_test mamoth ${GTEST_LIBRARIES} pthread)

# Add a test target to run the unit tests
# add_test(NAME mamoth_test COMMAND mamoth_test)