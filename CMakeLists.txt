cmake_minimum_required(VERSION 3.16)
project(Kalkulator LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    src/main.cpp
    inc/mainwindow.ui
    inc/mainwindow.h
    src/mainwindow.cpp
    inc/calculator.h
    src/calculator.cpp
)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

add_library(Calculator STATIC inc/calculator.h src/calculator.cpp)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Calculator
)
#ponizsza czesc wykonana z pomoca Copilot
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)


add_executable(${PROJECT_NAME}_tests tests/calculator_tests.cpp)
target_include_directories(${PROJECT_NAME}_tests PRIVATE inc)

target_link_libraries(${PROJECT_NAME}_tests
    PRIVATE
        gtest
        gtest_main
        Calculator
)

enable_testing()
add_test(NAME CalculatorTests COMMAND ${PROJECT_NAME}_tests)