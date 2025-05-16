#pragma once

#include "AForm.hpp"

class ShrubberyCreation : public AForm {
 private:
  std::string target;

 public:
  ShrubberyCreation();
  ShrubberyCreation(const std::string& target);
  ShrubberyCreation(const ShrubberyCreation& other);
  ShrubberyCreation& operator=(const ShrubberyCreation& other);
  ~ShrubberyCreation();

  void execute(const Bureaucrat& executor) const override;
};