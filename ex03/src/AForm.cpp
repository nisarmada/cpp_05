#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

const char* AForm::GradeTooHighException::what() const noexcept {
	return ("Grade is too High !");
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return ("Grade is too low !!");
}

const char* AForm::FormNotSignedException::what() const noexcept {
	return ("Form is not signed !");
}

AForm::AForm() : name("noname"), gradeSign(150), gradeExecute(150) {}

AForm::AForm(std::string name, const int gradeSign, const int gradeExecute) : name(name), gradeSign(gradeSign), gradeExecute(gradeExecute) {
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), \
 gradeSign(other.gradeSign), gradeExecute(other.gradeExecute) {}


AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return (*this);
}

bool AForm::getIsSigned() const {
	return (isSigned);
}

int AForm::getGradeSign() const {
	return (gradeSign);
}

int AForm::getGradeExecute() const {
	return (gradeExecute);
}

const std::string& AForm::getName() const {
	return (name);
}

void AForm::beSigned(const Bureaucrat& other) {
	if (gradeSign >= other.getGrade())
	{
		isSigned = true;
		std::cout << other.getName() << " signed " << name << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& stream, const AForm& form)
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

void AForm::checkExecution(const Bureaucrat& executor) const {
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeExecute)
		throw GradeTooLowException();
}