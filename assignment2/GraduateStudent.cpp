#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent() : Student(), fullTime(false) {}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime) : 
    Student(name, fines, fees), fullTime(fullTime) {}

double GraduateStudent::MoneyOwed() const {
    return this->GetLibraryFines();
}

