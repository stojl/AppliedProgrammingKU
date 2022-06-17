#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string prob) :
    Exception("File not open", prob) {}