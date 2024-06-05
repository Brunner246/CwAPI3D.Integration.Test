cmake_minimum_required(VERSION 3.28)
project(CwAPI3D.Integration.Test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPM_DOWNLOAD_LOCATION "${CMAKE_SOURCE_DIR}/cmake/CPM.cmake")
include(${CPM_DOWNLOAD_LOCATION})
CPMAddPackage("gh:gabime/spdlog@1.x")
CPMAddPackage(
        NAME cwapi3d
        GITHUB_REPOSITORY cwapi3d/cwapi3dcpp
        GIT_TAG main
)

set(SPDLOG_BUILD_EXAMPLE_HO ON)

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/src/")


add_library(${PROJECT_NAME} SHARED)

target_sources(${PROJECT_NAME} PRIVATE
        src/cwapi3d_test_library.cpp
        src/cwapi3d_test_controller.h
        src/cwapi3d_test_controller.cpp
        src/cwapi3d_test_utils.cpp
        src/cwapi3d_test_utils.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
MESSAGE(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_BINARY_DIR}/_deps/cwapi3d-src/include/cwapi3d)


set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_NAME ${PROJECT_NAME}.${COMPILER_TYPE}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        CWAPI3D_PLUGIN_NAME=L"CwAPI3D.Integration.Test"
        CWAPI3D_AUTHOR_NAME=L"Michael Brunner"
        CWAPI3D_AUTHOR_EMAIL=L"brunner@cadwork.swiss"
)


