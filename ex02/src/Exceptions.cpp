#include "../include/Bureaucrat.hpp"

const char* GradeTooHighException::what() const noexcept {
	return ("Grade is too high !");
}

const char* GradeTooLowException::what() const noexcept {
	return ("Grade is too low !");
}