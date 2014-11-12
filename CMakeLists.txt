cmake_minimum_required(VERSION 2.8)

project(ascii-pr0n)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CURSES_NEED_NCURSES TRUE)
find_package(Curses)

file(GLOB COMMON_SRC
    "source/cubes.cpp"
    "source/main.cpp"
    "source/palette.cpp"
    "source/zoomer.cpp"
    "source/pattern.cpp"
    "source/fire.cpp"
    "source/rotozoomer.cpp"
    "source/bars.cpp"
    )

include_directories(
    "source/"
    ${CURSES_INCLUDE_DIR}
    )

message("${COMMON_SRC}")

add_executable(${CMAKE_PROJECT_NAME} ${COMMON_SRC})

target_link_libraries(${CMAKE_PROJECT_NAME}
    ${CURSES_LIBRARIES}
    )
