#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

const char* Form::GradeTooHighException::what() const noexcept {
	return ("Grade is too High !");
}

const char* Form::GradeTooLowException::what() const noexcept {
	return ("Grade is too low !!");
}

Form::Form() : name("noname"), gradeSign(150), gradeExecute(150) {}

Form::Form(std::string name, const int gradeSign, const int gradeExecute) : name(name), gradeSign(gradeSign), gradeExecute(gradeExecute) {
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), \
 gradeSign(other.gradeSign), gradeExecute(other.gradeExecute) {}


Form& Form::operator=(const Form& other) {
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return (*this);
}

bool Form::getIsSigned() const {
	return (isSigned);
}

int Form::getGradeSign() const {
	return (gradeSign);
}

int Form::getGradeExecute() const {
	return (gradeExecute);
}

const std::string& Form::getName() const {
	return (name);
}

void Form::beSigned(const Bureaucrat& other) {
	if (gradeSign >= other.getGrade())
	{
		isSigned = true;
		std::cout << other.getName() << " signed " << name << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& stream, const Form& form)
{
	stream << form.getName();
	if (form.getIsSigned() == true)
		stream << " is signed ";
	else
		stream << " isn't signed";
	stream << ", needs " << form.getGradeSign() << " to be signed and " \
	<< form.getGradeExecute() << " to be executed" << std::endl;
	return stream;
}