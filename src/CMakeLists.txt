cmake_minimum_required(VERSION 3.12)
project("empty_plugin_cmake")

set(CMAKE_MODULE_PATH $ENV{CMAKE_MODULE_PATH})

if(WIN32)
    file(TO_CMAKE_PATH $ENV{MAYA_LOCATION} MAYA_LOCATION)
else()
    set(MAYA_LOCATION, $ENV{MAYA_LOCATION})
endif()

find_package(Maya REQUIRED)

set(SOURCE_FILES
   main.cpp
)

set(LIBRARIES
	OpenMaya
	Foundation
)

include_directories(${MAYA_INCLUDE_DIRS})

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${MAYA_LIBRARIES})

MAYA_SET_PLUGIN_PROPERTIES(${PROJECT_NAME})

# In my version of VS, this line is necessary for the install menu item to populate
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}${MAYA_EXTENSION}" DESTINATION ${CMAKE_INSTALL_PREFIX})
