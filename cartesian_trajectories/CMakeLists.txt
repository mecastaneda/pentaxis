cmake_minimum_required(VERSION 2.8.3)
project(cartesian_trajectories)

find_package(catkin REQUIRED COMPONENTS 
	roscpp 
	moveit_ros_planning_interface 
	industrial_trajectory_filters 
	#cmake_modules
	)

#find_package(Eigen REQUIRED)
#include_directories(${EIGEN_INCLUDE_DIRS})
#add_definitions(${EIGEN_DEFINITIONS})

include_directories(${industrial_trajectory_filters_INCLUDE_DIRS})

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES trajectory_tutorials
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

add_executable(sine src/sine.cpp)
target_link_libraries(sine ${catkin_LIBRARIES} )

add_executable(circle src/circle.cpp)
target_link_libraries(circle ${catkin_LIBRARIES} )

add_executable(square src/square.cpp)
target_link_libraries(square ${catkin_LIBRARIES} )

add_executable(ellipse src/ellipse.cpp)
target_link_libraries(ellipse ${catkin_LIBRARIES} )
