#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		int getGrade() const;
		const std::string& getName() const;
		void incrementGrade();
		void decrementGrade();
};

class GradeTooHighException : public std::exception {
	const char* what() const noexcept override;
};

class GradeTooLowException : public std::exception {
	const char* what() const noexcept override;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);