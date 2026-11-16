#ifndef FIM_HPP
#define FIM_HPP

#include <string>

#define SHA_256_STRING 257
#define BUFFER_MAX 2096

#define FILE_OPEN_ERROR "ERROR: Could not open the file"

//Saves the state of a file
struct FileState {
	std::string path;
	std::string sha256;
};


#endif 