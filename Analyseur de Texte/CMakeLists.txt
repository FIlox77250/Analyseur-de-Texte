cmake_minimum_required(VERSION 3.10)
project(Analyseur_de_Texte)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} WIN32 main.cpp)

target_link_libraries(${PROJECT_NAME}
        comctl32
        gdi32
        user32
        kernel32
)

target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE _UNICODE)