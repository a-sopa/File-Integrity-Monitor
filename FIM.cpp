#include "FIM.hpp"
#include <iostream>
#include <filesystem>
#include <fcntl.h>
#include <unistd.h>

//sha256sum File-Integrity-Monitor/main.cpp

namespace fs = std::filesystem;

std::string read_file(const std::string &filepath){
	std::string buffer[BUFFER_MAX];
	
	int fd = open(filepath.c_str(), O_RDONLY);

	if (fd < 0){
		close(fd);
		return FILE_OPEN_ERROR;
	}

	ssize_t bytes_read;
	while ((bytes_read = read(fd, buffer, sizeof(buffer)) > 0))
		
}