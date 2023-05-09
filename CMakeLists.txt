cmake_minimum_required(VERSION 3.22)

project(
        cppHelper
        VERSION 1.0
        LANGUAGES CXX
)

#

# Add the google test subdirectory
add_subdirectory(external/googletest)

# googletest
include_directories(external/googletest/googletest/include)

# googlemock
include_directories(external/googletest/googlemock/include)

# Compiler flags
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-g -Wall -Werror")

# Sources to be used in executable and/or tests, i.e: non main containing
# sources
FILE(GLOB COMMON_SOURCES
    lib/**/*.cc
)

# Exec source
FILE(GLOB EXEC_SOURCE
        executables/main/main.cc
)

# Test sources
FILE(GLOB TEST_SOURCE
        executables/test/**/*.cc
        )

FILE(GLOB PLAYGROUND_SOURCE
        executables/playground/main.cc
        )

# Prod Exec
add_executable(cppHelper ${COMMON_SOURCES} ${EXEC_SOURCE})

# Playground Exec
add_executable(playground ${COMMON_SOURCES} ${PLAYGROUND_SOURCE})

# Test execs
add_executable(cppHelperTest ${COMMON_SOURCES} ${TEST_SOURCE})

target_link_libraries(
        cppHelperTest
        gtest gtest_main
)

include(GoogleTest)
gtest_discover_tests(cppHelperTest)

