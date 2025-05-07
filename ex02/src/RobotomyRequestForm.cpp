#include "../include/RobotomyRequestForm.hpp"
#include "ctime"
#include "random"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), target("target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	checkExecution(executor);

	std::cout << "Drrrrrrrrrr.... Bzzzzzzz.." <<std::endl;
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	if (std::rand() % 2) {
		std::cout << "The Robotomy on " << target << " was successful !" << std::endl;
	}
	else {
		std::cout << "The Robotomy failed:(" << std::endl;
	}
}