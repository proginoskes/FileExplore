cmake_minimum_required(VERSION 3.26)

project(BrowserProj
    VERSION 0.0.1
)
set(CMAKE_CXX_STANDARD 17)


add_executable(BrowserProj)

target_sources(BrowserProj
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp   
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/WindowMediator.cpp   
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/WindowMediator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/Window.cpp   
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/Window.h   
)


set(INCL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes)

message(${INCL_DIR})

target_include_directories(BrowserProj
    SYSTEM PRIVATE
        ${INCL_DIR}
        
)

target_link_libraries(BrowserProj
    ${INCL_DIR}/GLFW/glfw3.lib
)

