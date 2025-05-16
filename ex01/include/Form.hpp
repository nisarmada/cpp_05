#pragma once

#include "Bureaucrat.hpp"
#include <stdbool.h>

class Form {
	private:
		const std::string name;
		bool isSigned = false;
		const int gradeSign;
		const int gradeExecute;
	public:
		Form();
		Form(std::string name, const int gradeSign, const int gradeExecute);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		const std::string& getName() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		// bool getBool() const;
		void beSigned(const Bureaucrat& other);
		bool getIsSigned() const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& stream, const Form& form);