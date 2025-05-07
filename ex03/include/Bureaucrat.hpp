#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class AForm;
 
class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		int getGrade() const;
		const std::string& getName() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& other);
		void executeForm(const AForm& form) const;
};

class GradeTooHighException : public std::exception {
	const char* what() const noexcept override;
};

class GradeTooLowException : public std::exception {
	const char* what() const noexcept override;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);