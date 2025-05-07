#include "../include/ShrubberyCreation.hpp"

ShrubberyCreation::ShrubberyCreation() : AForm("Shrubbery Creation", 145, 137), target("target"){}

ShrubberyCreation::ShrubberyCreation(std::string target) : AForm("Shrubbery Creation", 145, 137), target(target) {}

void ShrubberyCreation::execute(const Bureaucrat& executor) const {
	checkExecution(executor);

	std::ofstream file(target + "_shrubbery");
	if (!file.is_open()) {
		std::cerr << "Error: Failed to create the Shrubbery file !" <<std::endl;
	}
	file << "       _-_\n"
         << "    /~~   ~~\\\n"
         << " /~~         ~~\\\n"
         << "{               }\n"
         << " \\  _-     -_  /\n"
         << "   ~  \\\\ //  ~\n"
         << "_- -   | | _- _\n"
         << "  _ -  | |   -_\n"
         << "      // \\\\\n";
	file.close();
	std::cout << "Shrubbery tree was planted in " << target << "_shrubbery !" << std::endl;
}

