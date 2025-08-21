cmake_minimum_required(VERSION 3.16)

project(Projeto3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Projeto3
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        figurageometrica.cpp
        figurageometrica.h figurageometrica.cpp
        ../Projeto2/sculptor.h
        ../Projeto2/sculptor.h
        sculptor.h sculptor.cpp
        sculptor.h sculptor.cpp
        voxel.h
        putvoxel.h putvoxel.cpp
        cutvoxel.h cutvoxel.cpp
        putbox.h putbox.cpp
        cutbox.h cutbox.cpp
        putsphere.h putsphere.cpp
        cutsphere.h cutsphere.cpp
        cutsphere.h cutsphere.cpp
        cutsphere.h cutsphere.cpp
        putellipsoid.h putellipsoid.cpp
        cutellipsoid.h cutellipsoid.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Projeto3 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Projeto3 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Projeto3
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Projeto3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Projeto3)
endif()
set_target_properties(Projeto3 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Projeto3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Projeto3)
endif()
