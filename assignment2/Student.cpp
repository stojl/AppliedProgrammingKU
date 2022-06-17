#include "Student.hpp"


Student::Student() {
    library_fines = 0;
    tuition_fees = 0; 
    name = "Bob";
}

Student::Student(std::string name, double fines, double fees) 
{
    if(fines < 0) throw std::invalid_argument("Fine must be positive.");

    this->name = name;
    library_fines = fines;
    tuition_fees = fees;
}

void Student::SetLibraryFines(double amount)
{
    if(amount < 0) return;
    library_fines = amount;
}

double Student::MoneyOwed() const
{
    return library_fines + tuition_fees;
}