 cmake_minimum_required(VERSION 3.14)

project(hello LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(hello SHARED
  hello_global.h
  hello.cpp
  hello.h
)

target_link_libraries(hello PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(hello PRIVATE HELLO_LIBRARY)

include (GNUInstallDirs)
install (TARGETS hello
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

include(CMakePackageConfigHelpers)
configure_package_config_file(HelloConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/HelloConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Hello)

install (FILES ${CMAKE_CURRENT_BINNARY_DIR}/HelloConfig.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Hello)
