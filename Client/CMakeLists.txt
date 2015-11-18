# Usefull variables
# CMAKE_CURRENT_SOURCE_DIR = Racine du projet, dans les faits c'est le dossier ou est spécifié le CMakeLists.txt top level

cmake_minimum_required(VERSION 3.3)

project(RTypeClient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# COMPILATION DU CLIENT


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/client)

file(GLOB CLIENTSOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Client/src/*.cpp)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Client/Include ")

add_executable(RTypeClient ${CLIENTSOURCES})

# SFML CONFIG

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_ROOT "${PROJECT_SOURCE_DIR}/Client/SFML-2.3.2-win")

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/Client/cmake_modules")


find_package(SFML 2.3.2 REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(RTypeClient ${SFML_LIBRARIES})

    target_link_libraries(RTypeClient 
    					${PROJECT_SOURCE_DIR}/Client/SFML-2.3.2-win/lib/flac.lib
    					${PROJECT_SOURCE_DIR}/Client/SFML-2.3.2-win/lib/freetype.lib
    					${PROJECT_SOURCE_DIR}/Client/SFML-2.3.2-win/lib/jpeg.lib
    					${PROJECT_SOURCE_DIR}/Client/SFML-2.3.2-win/lib/ogg.lib
    					${PROJECT_SOURCE_DIR}/Client/SFML-2.3.2-win/lib/openal32.lib
    					${PROJECT_SOURCE_DIR}/Client/SFML-2.3.2-win/lib/vorbis.lib
    					${PROJECT_SOURCE_DIR}/Client/SFML-2.3.2-win/lib/vorbisenc.lib
    					${PROJECT_SOURCE_DIR}/Client/SFML-2.3.2-win/lib/vorbisfile.lib
    					winmm.lib
    					opengl32.lib	
    					)

endif(SFML_FOUND)

# END SFML CONFIG