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

link_directories("${CMAKE_CURRENT_LIST_DIR}/Lib/PolyHook_2_0/_install/lib/")

add_library(EchoClient SHARED)

add_subdirectory(Source)

target_include_directories(EchoClient PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Lib/PolyHook_2_0/_install/include")
target_link_libraries(EchoClient PRIVATE PolyHook_2 capstone)