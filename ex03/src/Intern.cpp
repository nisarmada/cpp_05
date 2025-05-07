#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreation.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm* createShrubbery(const std::string& target) {
	std::cout << "Intern has created a Shrubbery Creation" << std::endl;
	return new ShrubberyCreation(target);
}

AForm* createPardon(const std::string& target) {
	std::cout << "Intern has created a Presidential Pardon" << std::endl;
	return new PresidentialPardonForm(target);
}

AForm* createRobotomy(const std::string& target) {
	std::cout << "Intern has created a Robotomy Request" << std::endl;
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	FormPair forms[] = {
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPardon},
		{"shrubbery creation", createShrubbery}
	};

	for (int i = 0; i < 3; i++) {
		if (forms[i].name == name) {
			return (forms[i].create(target));
		}
	}
	std::cout << "Intern has failed to create " << name << " because it doesn't exist" << std::endl;
	return (nullptr);
}