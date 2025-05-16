#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

void testBureaucrat() {
    std::cout << "\n==== TESTING BUREAUCRAT ====\n";
    try {
        Bureaucrat john("John", 75);
        std::cout << john << std::endl;

        john.incrementGrade();
        std::cout << john << std::endl;

        john.decrementGrade();
        john.decrementGrade();
        std::cout << john << std::endl;

        Bureaucrat boss("Boss", 0);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try{
        Bureaucrat intern("Intern", 151);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
     try {
        Bureaucrat elite("Elite", 1);
        elite.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat lowly("Lowly", 150);
        lowly.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testForm() {
    std::cout << "\n==== TESTING FORM ====\n";
    try {
        Form form1("Form1", 100, 50);
        std::cout << form1 << std::endl;

        Bureaucrat bob("Bob", 90);
        bob.signForm(form1);
        std::cout << form1 << std::endl;

        Form copyForm(form1);
        std::cout << "Copy: " << copyForm << std::endl;

        Form assignedForm("AssignedForm", 10, 10);
        assignedForm = form1;
        std::cout << "Assigned: " << assignedForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
     try {
        Form invalidFormHigh("InvalidHigh", 0, 1);
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Form invalidFormLow("InvalidLow", 151, 1);
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    testBureaucrat();
    testForm();
    return 0;
}
