# More than one executable can be added, but make sure to give it a unique name and link thet library
add_executable (ConeTest cone.cpp )
target_link_libraries (ConeTest LINK_PUBLIC lib)

# More than one executable can be added, but make sure to give it a unique name and link thet library
add_executable (SphereTest sphere.cpp)
target_link_libraries (SphereTest LINK_PUBLIC lib)