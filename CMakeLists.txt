cmake_minimum_required(VERSION 3.28)
project(CwAPI3D.Integration.Test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CADLIB_DIR "C:/source/cadlib")
set(CADWORK_VERSION 30)

INCLUDE_DIRECTORIES(
        "./CwAPI3D/includes"
        # "${CADLIB_DIR}/v_${CADWORK_VERSION}.0/3d/CwAPI3D"
)

add_library(${PROJECT_NAME} SHARED
        library.cpp
        elementControllerIT.h
        elementControllerIT.cpp
        Logger.cpp
)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(COMPILER_TYPE "gcc")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(COMPILER_TYPE "clang")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(COMPILER_TYPE "msvc")
endif()

set_target_properties(${PROJECT_NAME}  PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}.${COMPILER_TYPE}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        CWAPI3D_PLUGIN_NAME=L"CwAPI3D.Integration.Test"
        CWAPI3D_AUTHOR_NAME=L"Michael Brunner"
        CWAPI3D_AUTHOR_EMAIL=L"brunner@cadwork.swiss"
)
