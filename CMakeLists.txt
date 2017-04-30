cmake_minimum_required(VERSION 3.2)
project(KPang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")


set(SOURCE_FILES main.cpp KPang.cpp SplashScreen.cpp stdafx.cpp MainMenu.cpp VisibleGameObject.cpp PlayerPaddle.cpp)
add_executable(KPang ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(KPang ${SFML_LIBRARIES})
endif()