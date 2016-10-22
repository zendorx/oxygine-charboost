cmake_minimum_required (VERSION 2.6)
project (OXYGINE_CHARBOOST)

set(OXYGINE_CHARBOOST_INCLUDE_DIRS 
	${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${OXYGINE_CHARBOOST_INCLUDE_DIRS})
add_library(oxygine-charboost STATIC 
	src/charboost.cpp 
	src/charboost.h
	src/sim/CharboostSimulator.cpp 
	src/sim/CharboostSimulator.h
)

#target_link_libraries(oxyginemagicparticles)

set(OXYGINE_CHARBOOST_INCLUDE_DIRS ${OXYGINE_CHARBOOST_INCLUDE_DIRS} PARENT_SCOPE)
set(OXYGINE_CHARBOOST_LIBS ${OXYGINE_CHARBOOST_LIBS} PARENT_SCOPE)