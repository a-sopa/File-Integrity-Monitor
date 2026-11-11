#ifndef FIM_HPP
#define FIM_HPP

#include <string>


//Saves the state of a file
struct FileState {
    std::string path;
    std::string sha256;
};


#endif 