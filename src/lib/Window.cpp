#include "./Window.h"

#include <GLFW/glfw3.h>
#include <windows.h>
#include <iostream>

void Window::runLoop(Window *window){
    while(!window->runSingleIteration()){

#ifndef NDEBUG

        /*
        std::cout << "Running single iteration" <<std::endl;
        Sleep(500);
        */

#endif
    }

    return;
}

bool Window::runSingleIteration(){ 

    glfwSwapBuffers(m_hWind);

    m_end =  glfwWindowShouldClose(m_hWind);

    return m_end;

}

bool Window::getShouldEnd() {
    return m_end;
}

std::optional<std::unique_ptr<Window>> Window::create(int width, int height, const char* title){
    GLFWwindow *hWind = glfwCreateWindow(
        width,
        height,
        title,
        NULL,
        NULL
    );

    if(!hWind){
        return std::nullopt;
    }

    glfwMakeContextCurrent(hWind);

    return std::unique_ptr<Window>(new Window(hWind));
}

Window::~Window(){

#ifndef NDEBUG
    std::cout << "closing Window" <<std::endl;
#endif

    //glfwSetWindowShouldClose(m_hWind,GLFW_TRUE);
    m_thread.join();

#ifndef NDEBUG
    std::cout << "destroying Window" <<std::endl;
#endif

    glfwDestroyWindow(m_hWind);
}

Window::Window(GLFWwindow *hWind):m_hWind(hWind), m_thread(runLoop, this) {

#ifndef NDEBUG
    std::cout << "creating Window" <<std::endl;
#endif
}
