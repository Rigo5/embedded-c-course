add_library(buffer STATIC
    src/buffer.c
)

target_include_directories(buffer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)