#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

Bureaucrat::Bureaucrat() : name("NoName"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		grade = other.grade;
	return (*this);
}

int Bureaucrat::getGrade() const {
	return grade;
}

const std::string& Bureaucrat::getName() const {
	return name;
}

void Bureaucrat::incrementGrade() {
	if (grade <= 1)
		throw GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150)
		throw GradeTooLowException();
	else
		grade++;
}

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
	}
	catch (const Form::GradeTooLowException& e) {
		std::cout << name << " couldn't sign the " << form.getName()\
		<< " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat) {
	stream << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade();
	return (stream);
}
