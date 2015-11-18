# Usefull variables
# CMAKE_CURRENT_SOURCE_DIR = Racine du projet, dans les faits c'est le dossier ou est spécifié le CMakeLists.txt

cmake_minimum_required(VERSION 3.3)

project(RTypeServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")



# COMPILATION DU SERVER

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/server)

file(GLOB SERVERSOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Server/src/*.cpp)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Server/Include")

add_executable(RTypeServer ${SERVERSOURCES})

