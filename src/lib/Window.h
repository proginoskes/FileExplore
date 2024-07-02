#pragma once

#include <GLFW/glfw3.h>
#include <memory>
#include <optional>
#include <thread>
#include <mutex>
#include <future>


class Window {
    private:
        GLFWwindow* m_hWind;
        std::thread m_thread;
        std::atomic<bool> m_end;

        Window(GLFWwindow *hWind);
    public:

        static void runLoop(Window *window);

        bool runSingleIteration();

        bool getShouldEnd();

        static std::optional<std::unique_ptr<Window>> create(int width, int height, const char* title);
        ~Window();
};
