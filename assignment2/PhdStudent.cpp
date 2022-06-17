#include "PhdStudent.hpp"

PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime) : 
    GraduateStudent(name, fines, fees, fullTime) {}

double PhdStudent::MoneyOwed() const
{
    return 0;
}