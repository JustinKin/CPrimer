cmake_minimum_required(VERSION 3.0.0)

project(main VERSION 0.1.0)

SET(CMAKE_CXX_COMPILER "/usr/bin/g++") # 默认c++编译器

SET(CMAKE_BUILD_TYPE "Debug")  # 选项: Release Debug MinSizeRel RelWithDebInfo

SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin") # 可执行文件输出目录

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include") 

add_library(main_library SHARED 
    src/IOtest.cpp
    src/function.cpp
    src/sales_data.cpp
)
add_library(main::library ALIAS main_library)

target_include_directories(main_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(main
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( main
    PRIVATE 
    main::library
)
