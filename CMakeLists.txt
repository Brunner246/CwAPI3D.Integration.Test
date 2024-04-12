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
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        CWAPI3D_PLUGIN_NAME=L"CwAPI3D.Integration.Test"
        CWAPI3D_AUTHOR_NAME=L"Michael Brunner"
        CWAPI3D_AUTHOR_EMAIL=L"brunner@cadwork.swiss"
)
