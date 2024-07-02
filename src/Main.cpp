#include "lib/ExampleAppRunner.h"
#include "lib/Directory.h"
#include<windows.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>
#include <optional>

int main() {

    std::optional<std::unique_ptr<AppRunner<ExampleAppRunner>>> opAppRunner 
        = AppRunner<ExampleAppRunner>::start();

    if(!opAppRunner.has_value()){
#ifndef NDEBUG
        std::cout << "could not create window mediator" << std::endl;
#endif
        return -1;
    }

    opAppRunner.value()->openWindow(800, 600, "UniqueWindow");

    opAppRunner.value()->runLoop();

    /*
    std::optional<std::unique_ptr<Directory>> dir = Directory::open(
        "C:\\Users\\kouck\\Sandbox"
    );
    */

    return 0;

}
