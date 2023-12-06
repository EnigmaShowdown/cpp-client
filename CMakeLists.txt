cmake_minimum_required(VERSION 3.12)
project(EnigmaShowdownCppClient)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)


# Add your source files

# Add source files from the customClientVariables directory
file(GLOB CLIENT_VARIABLES_SOURCES customClientVariables/*.cpp)

# Add source files from the current directory
file(GLOB CURRENT_DIR_SOURCES *.cpp)

# Combine the lists
set(SOURCE_FILES
    ${CLIENT_VARIABLES_SOURCES}
    ${CURRENT_DIR_SOURCES}
)


# Find and include cppzmq library
find_package(cppzmq REQUIRED)

# Create the executable
add_executable(CppClient ${SOURCE_FILES})

# Link the executable with cppzmq library
target_link_libraries(CppClient PRIVATE cppzmq)

# Include header files from cppzmq
target_include_directories(CppClient PRIVATE ${cppzmq_INCLUDE_DIR})
