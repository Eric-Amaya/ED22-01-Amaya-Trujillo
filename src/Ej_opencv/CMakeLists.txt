cmake_minimum_required(VERSION 3.0.0)
project(Ej_opencv VERSION 0.1.0)

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )    
include_directories( "src" )


add_executable(Ej_opencv Nodo.cpp ListaPersonas.cpp Detector.cpp Persona.cpp main.cpp)

target_link_libraries( Ej_opencv ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
