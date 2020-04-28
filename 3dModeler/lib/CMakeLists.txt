add_library (lib STATIC "Solid.cpp")
target_include_directories (lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory("vectors")
target_link_libraries(lib LINK_PUBLIC vectors)

