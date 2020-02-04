cmake_minimum_required(VERSION 3.9)
project(NCursesConnectN LANGUAGES C)

set(CMAKE_C_STANDARD 11)


set(CURSES_USE_NCURSES TRUE)
find_package(Curses REQUIRED)


add_executable(NCursesConnectN main.c cursorTrackWindow.c cursorTrackWindow.h board.c board.h move.c move.h inputValidation.c inputValidation.h win.c win.h)
set_target_properties(NCursesConnectN PROPERTIES OUTPUT_NAME "NCursesConnectN" SUFFIX ".out")




target_compile_options(NCursesConnectN PRIVATE -Wall -Werror)
target_link_libraries(NCursesConnectN PRIVATE ${CURSES_LIBRARIES})
target_include_directories(NCursesConnectN PRIVATE ${CURSES_INCLUDE_DIRS})
