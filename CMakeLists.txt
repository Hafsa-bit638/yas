cmake_minimum_required(VERSION 3.16)
project(Projet_gtk)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(Projet_gtk main.c
        coordonnees.h
        global.h
        dimension.h
        icone.h
        image.h
        window.h
        colors.h
        Button.h)

target_link_libraries(Projet_gtk ${GTK3_LIBRARIES})