#pragma once

#include "AForm.hpp"

class ShrubberyCreation : public AForm {
	private:
		std::string target;
	public:
		ShrubberyCreation();
		ShrubberyCreation(std::string target);
		void execute(const Bureaucrat& executor) const override;
};