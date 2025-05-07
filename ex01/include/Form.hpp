#pragma once
#include "Bureaucrat.hpp"

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
		bool getIsSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		const std::string& getName() const;

		void beSigned(const Bureaucrat& other);
		
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

