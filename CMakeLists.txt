# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.15)

# set the project name and version
#project(Tutorial VERSION 1.0)
# Set the project name
set(APP_NAME cmakeTutorial)
set(CMAKE_BUILD_TYPE Debug)
project(${APP_NAME} VERSION 2.3)


# Specifying the C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial provided math implementation" ON)


# configure a header file to pass the version number only
configure_file(cmakeTutorialConfig.h.in cmakeTutorialConfig.h)




# add the executable
#add_executable(Tutorial tutorial.cxx)
add_executable(${APP_NAME}  main.cxx)




                                     

message(STATUS "PROJECT_BINARY_DIR is " ${PROJECT_BINARY_DIR})



if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

target_link_libraries(${APP_NAME}  PUBLIC ${EXTRA_LIBS})      

# add the binary tree to the search path for include files
# so that we will find cmakeTutorialConfig.h
target_include_directories(${APP_NAME}  PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )