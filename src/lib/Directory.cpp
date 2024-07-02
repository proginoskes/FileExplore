#include "Directory.h"


Directory::Directory(fs::path path) : 
	m_path(path) {
#ifndef NDEBUG
	std::cout << "creating Directory Object" << std::endl;
#endif
}

std::optional<std::unique_ptr<Directory>> Directory::open(fs::path path) {
	
	if (!fs::is_directory(path)) {
		return {};
	}

	return std::unique_ptr<Directory>(new Directory(
		path
	));
}

Directory::~Directory() {
#ifndef NDEBUG
	std::cout << "closing Directory Object" << std::endl;
#endif

#ifndef NDEBUG
	std::cout << "destroying Directory Object" << std::endl;
#endif

}

