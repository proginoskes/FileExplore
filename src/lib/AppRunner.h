#pragma once

#include <iostream>
#include <optional>

#include "WindowMediator.h"

template<class T>
class AppRunner {
private:

	// if wanted, could make this dependent on a macro
	std::unique_ptr<WindowMediator> m_pWindowMediator;



	AppRunner<T>(std::unique_ptr<WindowMediator> pWindowMediator) : m_pWindowMediator(std::move(pWindowMediator)) {
#ifndef NDEBUG
		std::cout << "creating AppRunner" << std::endl;
#endif   
	}

public:
	static std::optional<std::unique_ptr<AppRunner<T>>> start() {

		std::optional<std::unique_ptr<WindowMediator>> opWindowMediator
			= WindowMediator::create();

		if (!opWindowMediator.has_value()) {
			return std::nullopt;
		}

		/*
		
		std::optional<arguments> args = T::additionalStartup();
		
		*/

		
		// make constructor variadic
		return std::unique_ptr<AppRunner<T>>(new AppRunner<T>(std::move(opWindowMediator.value())));

	}

	bool openWindow(int width, int height, const char* name) {

		return m_pWindowMediator->openWindow(width, height, name);

	}

	int runLoop() {
		while (m_pWindowMediator->getShouldEnd()) {
			static_cast<T*>(this)->mainFunction();
		}

		return 0;
	}

	//moveable
	AppRunner<T>& operator=(AppRunner<T>&& rv) = default;

	~AppRunner<T>() {
#ifndef NDEBUG
		std::cout << "destroying AppRunner" << std::endl;
#endif   
	}

};