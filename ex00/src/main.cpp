#include <iostream>
#include "../Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat john("John", 75);
        std::cout << john << std::endl;

        std::cout << "Incrementing" << std::endl;
        john.incrementGrade();
        std::cout << john << std::endl;

		std::cout << "decrementing" << std::endl;
        john.decrementGrade();
        john.decrementGrade();
        std::cout << john << std::endl;
		std::cout << "---invalid high---" << std::endl;
        Bureaucrat boss("Boss", 0);  // Should throw GradeTooHighException

    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "--invalid low---" << std::endl;
        Bureaucrat intern("Intern", 151);  // Should throw GradeTooLowException
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nCreating bureaucrat at grade 1 and incrementing..." << std::endl;
        Bureaucrat elite("Elite", 1);
        elite.incrementGrade();  // Should throw GradeTooHighException
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nCreating bureaucrat at grade 150 and decrementing..." << std::endl;
        Bureaucrat lowly("Lowly", 150);
        lowly.decrementGrade();  // Should throw GradeTooLowException
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
