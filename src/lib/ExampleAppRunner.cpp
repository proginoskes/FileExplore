#include "ExampleAppRunner.h"

/*
std::optional<std::unique_ptr<ExampleAppRunner>> ExampleAppRunner::start() {
	return std::optional<std::unique_ptr<ExampleAppRunner>>();
}
*/

void ExampleAppRunner::mainFunction() {
#ifndef NDEBUG
	std::cout << "run one loop" << "\r";
#endif
}
