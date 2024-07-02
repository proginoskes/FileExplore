#pragma once

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class Directory {
private:
	fs::path m_path;
	fs::directory_iterator m_iDir;

	Directory(fs::path path);

public:
	static std::optional<std::unique_ptr<Directory>> open(fs::path path);


	//moveable
	Directory& operator=(Directory&& rv) = default;

	~Directory();

};