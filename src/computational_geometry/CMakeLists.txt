
add_library(circle circle.cpp)
add_library(line line.cpp)
add_library(point point.cpp)
add_library(polygon polygon.cpp)
add_library(vec vec.cpp)
add_library(triangle triangle.cpp)
# add_library(blah blah.cpp)


# add_executable(comp_geo main.cpp)
target_link_libraries(
						circle
						line
						point
						polygon
						vec
						triangle
						
						)

						
# circle.cpp
# circle.h
# CMakeLists.txt
# line.cpp
# line.h
# main.cpp
# point.cpp
# point.h
# polygon.cpp
# polygon.h
# triangle.cpp
# triangle.h
# vec.cpp
# vec.h
