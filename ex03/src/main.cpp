#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreation.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    Intern someRandomIntern;

    AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form1) {
        std::cout << "Form1 created successfully!" << std::endl;
        delete form1;
    }

    AForm* form2 = someRandomIntern.makeForm("presidential pardon", "Alice");
    if (form2) {
        std::cout << "Form2 created successfully!" << std::endl;
        delete form2;
    }

    AForm* form3 = someRandomIntern.makeForm("nonexistent form", "Nobody");
    if (!form3) {
        std::cout << "Failed to create form3!" << std::endl;
    }

    AForm* form4 = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form4) {
        std::cout << "Form4 created successfully!" << std::endl;
        delete form4;
    }

    return 0;
}