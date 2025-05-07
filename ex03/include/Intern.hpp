#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;

class Intern {
	public:
		Intern();
		~Intern();
		
		AForm* makeForm(const std::string& name, const std::string& target);
		typedef AForm* (*FormCreator)(const std::string&);

		typedef struct forms {
			std::string name;
			FormCreator create;
		} FormPair;
};

	AForm* createShrubbery(const std::string& target);
	AForm* createPardon(const std::string& target);
	AForm* createRobotomy(const std::string& target);