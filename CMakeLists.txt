cmake_minimum_required(VERSION 3.20)

project(EmbeddedExercise C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(buffer)
add_subdirectory(device)

add_executable(firmware
    app/main.c
)

target_link_libraries(firmware PRIVATE buffer device)

target_compile_options(firmware
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)