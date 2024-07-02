#pragma once

#include "Window.h"


class Renderer{
    private:


        Renderer();

    public:
        static std::optional<std::unique_ptr<Renderer>> init();


        //moveable
        Renderer& operator=(Renderer&& rv) = default;

        ~Renderer();

};
