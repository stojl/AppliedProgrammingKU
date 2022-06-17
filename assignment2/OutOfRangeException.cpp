#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(std::string prob) : 
    Exception("Out of range", prob) {}
