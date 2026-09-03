add_library(moving-avg src/moving-avg.c)
target_include_directories(moving-avg PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)