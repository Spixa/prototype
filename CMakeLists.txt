
cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()



include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
ExternalProject_Add(SFML 
		GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1 
		#SOURCE_DIR  ${CMAKE_SOURCE_DIR}/ext/sfml 
    		CMAKE_ARGS 
			-DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
			-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE})
ExternalProject_Get_Property(SFML INSTALL_DIR)
set(SFML_LIB ${INSTALL_DIR})


project(Game VERSION 0.0.1)

set(SOURCE
    ${CMAKE_SOURCE_DIR}/src/main.cpp
		${CMAKE_SOURCE_DIR}/src/game.cpp
		${CMAKE_SOURCE_DIR}/src/axe.cpp
		${CMAKE_SOURCE_DIR}/src/scene.cpp
		${CMAKE_SOURCE_DIR}/src/entity.cpp
		${CMAKE_SOURCE_DIR}/src/animation.cpp
)

link_directories(${SFML_LIB}/lib)

find_package(SFML REQUIRED COMPONENTS audio network graphics window system)

add_executable(axe ${SOURCE})
target_include_directories(axe PRIVATE ${SFML_LIB}/include)


add_dependencies(axe SFML)

message(STATUS ${SFML_LIB})

TARGET_LINK_LIBRARIES(axe sfml-system sfml-window sfml-graphics sfml-audio sfml-network)