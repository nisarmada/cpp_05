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
    // Create an Intern object
    Intern someRandomIntern;

    // Test with a valid form: "robotomy request"
    AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form1) {
        std::cout << "Form1 created successfully!" << std::endl;
        // Remember to delete the dynamically allocated form
        delete form1;
    }

    // Test with another valid form: "presidential pardon"
    AForm* form2 = someRandomIntern.makeForm("presidential pardon", "Alice");
    if (form2) {
        std::cout << "Form2 created successfully!" << std::endl;
        delete form2;
    }

    // Test with an invalid form: "nonexistent form"
    AForm* form3 = someRandomIntern.makeForm("nonexistent form", "Nobody");
    if (!form3) {
        std::cout << "Failed to create form3!" << std::endl;
    }

    // Test with another valid form: "shrubbery creation"
    AForm* form4 = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form4) {
        std::cout << "Form4 created successfully!" << std::endl;
        delete form4;
    }

    return 0;
}