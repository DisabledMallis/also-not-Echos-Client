cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)
project(EchoClient VERSION 1.0 LANGUAGES CXX)

if(MSVC)
    add_compile_options(
            $<$<CONFIG:>:/MT>
            $<$<CONFIG:Debug>:/MTd>
            $<$<CONFIG:Release>:/MT>
    )
endif()

add_library(EchoClient SHARED)

add_subdirectory(Source)