#include "WindowMediator.h"
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>
#include <algorithm>
#include <windows.h>

WindowMediator::WindowMediator() : m_vWindows{}{
#ifndef NDEBUG
    std::cout << "creating WindowMediator" <<std::endl;
#endif   
}

void WindowMediator::closeWindows(){
    m_vWindows.clear();
}

bool WindowMediator::getShouldEnd() {
    glfwPollEvents();
    for (int i = 0; i < m_vWindows.size();i++) {

        if (m_vWindows.at(i)->getShouldEnd()) {
            m_vWindows.erase(m_vWindows.begin() + i);
        }

    }

    return m_vWindows.size();
}

bool WindowMediator::openWindow(
    int width, int height,
    const char* title
){
    std::optional<std::unique_ptr<Window>> newWindow = Window::create(
        width,height,title        
    );

    switch (newWindow.has_value()) {
    case false:
        return false;
    case true:
        m_vWindows.push_back(std::move(newWindow.value()));
        return true;
    }

}


    
std::optional<std::unique_ptr<WindowMediator>> WindowMediator::create(){
    if(!glfwInit()){
        return std::nullopt;
    }
    return std::unique_ptr<WindowMediator>(new WindowMediator());
}

WindowMediator::~WindowMediator(){

    m_vWindows.clear();

#ifndef NDEBUG
    std::cout << "destroying WindowMediator" <<std::endl;
#endif
    glfwTerminate();

}
