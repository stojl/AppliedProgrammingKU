#include "Exception.hpp"

Exception::Exception(std::string tagString, std::string probString) : mTag(tagString), mProblem(probString) {}

void Exception::PrintDebug() const
{
    std::cout << mTag << std::endl << mProblem << std::endl;
}