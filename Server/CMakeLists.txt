# Usefull variables
# CMAKE_CURRENT_SOURCE_DIR = Racine du projet, dans les faits c'est le dossier ou est spécifié le CMakeLists.txt

cmake_minimum_required(VERSION 3.0)

project(RTypeServer)
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -std=c++11 -pthread")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

# COMPILATION DU SERVER

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/server)

file(GLOB SERVERSOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Server/src/*.cpp)
file(GLOB SERVERCOMMONI ${CMAKE_CURRENT_SOURCE_DIR}/Commoni/src/*.cpp)
file(GLOB SERVERCOMMON ${CMAKE_CURRENT_SOURCE_DIR}/Common/src/*.cpp)

MESSAGE("${SERVERSOURCES}")
MESSAGE("${SERVERCOMMON}")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Server/includes")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Commoni/includes")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Common/inc")

add_executable(RTypeServer ${SERVERSOURCES} ${SERVERCOMMON} ${SERVERCOMMONI})
