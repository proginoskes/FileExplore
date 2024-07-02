#pragma once

#include <iostream>
#include <optional>

#include "AppRunner.h"

class ExampleAppRunner : public AppRunner<ExampleAppRunner> {

private:



public:
	//static std::optional<std::unique_ptr<ExampleAppRunner>> start();

	void mainFunction(); //required for class instantiation


};