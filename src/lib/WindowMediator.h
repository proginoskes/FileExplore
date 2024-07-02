#pragma once

#include "Window.h"

#include <GLFW/glfw3.h>
#include <memory>
#include <optional>
#include <vector>
#include <queue>

class WindowMediator{
    private:

        std::queue<std::string> m_qEvents;

        std::vector<std::unique_ptr<Window>> m_vWindows;

        WindowMediator();


    public:

        bool openWindow(
            int width, int height,
            const char* title
        ); 

        void closeWindows();

        bool getShouldEnd();

        static std::optional<std::unique_ptr<WindowMediator>> create();
        ~WindowMediator();

        //moveable
        WindowMediator& operator=(WindowMediator&& rv) = default;

};
