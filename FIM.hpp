#ifndef FIM_HPP
#define FIM_HPP

#include <iostream>
#include <filesystem>
#include <fcntl.h>
#include <unistd.h>
#include <openssl/evp.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <optional>
#include <cerrno>
#include <unordered_map>

using HashMap = std::unordered_map<std::string, std::string>;

#define SHA_256_STRING 257
#define BUFFER_MAX 2048

#define FILE_OPEN_ERROR "ERROR: Could not open the file"
#define EMPTY_DIR_ERROR "ERROR: Empty directory"

#define DIRECTORY_TO_READ "/tests"


//Saves the state of a file
struct FileState {
	std::string path;
	std::string sha256;
};

int scan_directory(const std::string &dir_path, std::vector<std::string> &files);
std::optional<std::string> read_file(const std::string &filepath);
std::string calculate_sha256(const std::string &file_data);
HashMap snapshot(const std::string &dir);

#endif 