#pragma once
#include "Bureaucrat.hpp"
#include <fstream>

class AForm {
	private:
		const std::string name;
		bool isSigned = false;
		const int gradeSign;
		const int gradeExecute;
	public:
		AForm();
		AForm(std::string name, const int gradeSign, const int gradeExecute);
		~AForm();

		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		bool getIsSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		const std::string& getName() const;

		void beSigned(const Bureaucrat& other);
		
		virtual void execute(const Bureaucrat& executor) const = 0;
		void checkExecution(const Bureaucrat& executor) const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& stream, const AForm& form);

