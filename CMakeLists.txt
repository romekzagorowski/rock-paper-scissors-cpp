cmake_minimum_required(VERSION 3.20)

project(rock_paper_scissors LANGUAGES CXX)

add_executable(rock_paper_scissors main.cpp)

set_target_properties(rock_paper_scissors PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

if(MINGW)
    target_link_libraries(rock_paper_scissors PRIVATE stdc++exp)
endif()
