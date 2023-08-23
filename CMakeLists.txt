cmake_minimum_required(VERSION 3.22)

project(
        cppHelper
        VERSION 1.0
        LANGUAGES CXX
)

# Compiler flags
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-g -Wall")

# Sources to be used in executable and/or tests, i.e: non main containing
# sources
FILE(GLOB COMMON_SOURCES
        lib/**/*.cc
        frontend/**/*.cc
        model/**/*.cc
        controller/**/*.cc
        )

# Exec source
FILE(GLOB EXEC_SOURCE
        executables/main/*.cc
        )

# Test sources
FILE(GLOB TEST_SOURCE
        executables/test/**/*.cc
        )

# ASL Zip
include(FetchContent)
FetchContent_Declare(asl URL https://github.com/aslze/asl/archive/1.11.8.zip)
FetchContent_MakeAvailable(asl)

include_directories(extern/aslzip/include)
add_subdirectory(extern/aslzip/src)

# Prod Exec
add_executable(cppHelper ${COMMON_SOURCES} ${EXEC_SOURCE})

target_link_libraries(cppHelper asls aslzip)
