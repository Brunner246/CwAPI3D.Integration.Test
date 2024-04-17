cmake_minimum_required(VERSION 3.28)
project(CwAPI3D.Integration.Test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CADLIB_DIR "C:/source/cadlib")
set(CADWORK_VERSION 30)

set(SPDLOG_BUILD_EXAMPLE_HO ON)

INCLUDE_DIRECTORIES(
        "./CwAPI3D/includes"
        ${PROJECT_SOURCE_DIR}
        # "${CADLIB_DIR}/v_${CADWORK_VERSION}.0/3d/CwAPI3D"
)

if (MSVC)
  add_definitions(-D_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING)
endif()

add_library(${PROJECT_NAME} SHARED
        cwapi3d.test.library.cpp
        cwapi3d.test.controller.h
        cwapi3d.test.controller.cpp
        Logger.cpp
        cwapi3d.test.utils.cpp
        cwapi3d.test.utils.h
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
        # SPDLOG_HEADER_ONLY
        CWAPI3D_PLUGIN_NAME=L"CwAPI3D.Integration.Test"
        CWAPI3D_AUTHOR_NAME=L"Michael Brunner"
        CWAPI3D_AUTHOR_EMAIL=L"brunner@cadwork.swiss"
)


