# do NOT include "Vector.cpp" because due to the template compilation the source is included in the header
add_library(vectors STATIC "Vector3D.cpp" "Vector3D.hpp" "Vector.hpp" "vectors.hpp")
target_include_directories (vectors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
