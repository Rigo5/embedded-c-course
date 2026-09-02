add_library(device STATIC
    src/device.c
)

target_include_directories(device PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)   