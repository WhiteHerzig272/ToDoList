cmake_minimum_required(VERSION 3.31)
project(ToDoList)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    # Статическая линковка стандартных библиотек
    set(CMAKE_EXE_LINKER_FLAGS "-static")

    # Флаг для Windows API (версия Windows 10)
    add_compile_definitions(_WIN32_WINNT=0x0A00)

    # Дополнительные флаги для MinGW (если используется)
    if (MINGW)
        add_compile_options(-static-libgcc -static-libstdc++)
    endif()
endif()

add_executable(ToDoList src/main.cpp
        src/file_io.cpp
        include/file_io.h)
