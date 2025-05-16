#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreation.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <chrono>
#include <thread>

// Function to print a separator line for better output readability
void printSeparator() {
    std::cout << "\n----------------------------------------\n" << std::endl;
}

int main() {
    try {
        // Creating bureaucrats with different grades
        Bureaucrat boss("Big Boss", 1);           // Highest possible grade
        Bureaucrat manager("Manager", 30);        // Mid-high grade
        Bureaucrat employee("Employee", 60);      // Mid grade
        Bureaucrat intern("Intern", 140);         // Low grade
        
        // Print all bureaucrats to verify creation
        std::cout << boss << manager << employee << intern;
        
        printSeparator();
        
        std::cout << "Shrubbery Creation Form." << std::endl;
        // Create a ShrubberyCreation form
        ShrubberyCreation shrubForm("garden");
        std::cout << "Created: " << shrubForm;
        
        // Test signing with different bureaucrats
        std::cout << "\nIntern signing (should work):" << std::endl;
        intern.signForm(shrubForm);
        
        // Try executing with different grades
        std::cout << "\nIntern executing (should fail):" << std::endl;
        intern.executeForm(shrubForm);
        
        std::cout << "\nEmployee executing (should work):" << std::endl;
        employee.executeForm(shrubForm);
        
        printSeparator();
        
        std::cout << "Robotomy Request Form!" << std::endl;
        RobotomyRequestForm robotForm("subject");
        std::cout << "Created: " << robotForm;
        
        std::cout << "\nIntern signing (should fail):" << std::endl;
        intern.signForm(robotForm);
        
        std::cout << "\nEmployee signing (should work):" << std::endl;
        employee.signForm(robotForm);
        
        std::cout << "\nEmployee executing (should fail):" << std::endl;
        employee.executeForm(robotForm);
        
        std::cout << "\nManager executing (should work):" << std::endl;
        manager.executeForm(robotForm);
        
        for (int i = 0; i < 5; i++) {
            manager.executeForm(robotForm);
        }
        
        printSeparator();
        
        std::cout << "Presidential Pardon Form" << std::endl;
        PresidentialPardonForm pardonForm("criminal");
        std::cout << "Created: " << pardonForm;
        
        std::cout << "\nManager signing (should fail):" << std::endl;
        manager.signForm(pardonForm);
        
        std::cout << "\nBoss signing (should work):" << std::endl;
        boss.signForm(pardonForm);
        
        std::cout << "\nManager executing (should fail):" << std::endl;
        manager.executeForm(pardonForm);
        
        std::cout << "\nBoss executing (should work):" << std::endl;
        boss.executeForm(pardonForm);
        
        printSeparator();
        
        std::cout << "Testing some exceptions..." << std::endl;
        
        std::cout << "\nTrying to execute an unsigned form:" << std::endl;
        RobotomyRequestForm unsignedForm("unsigned");
        boss.executeForm(unsignedForm);
        
        std::cout << "\nTrying to create bad bureaucrats:" << std::endl;
        std::cout << "Grade too high (0): ";
        Bureaucrat tooHigh("Too High", 0);
        
    } catch (std::exception& e) {
        std::cout << "Whoops! Exception: " << e.what() << std::endl;
    }
    
    printSeparator();
    
    try {
        ShrubberyCreation original1("original1");
        RobotomyRequestForm original2("original2");
        PresidentialPardonForm original3("original3");
        
        // Sign an original to test if sign status is copied
        Bureaucrat boss("Copy Test Boss", 1);
        boss.signForm(original1);
        
        std::cout << "\nCopy constructor:" << std::endl;
        ShrubberyCreation copy1(original1);
        RobotomyRequestForm copy2(original2);
        PresidentialPardonForm copy3(original3);
        
        std::cout << "Original: " << original1;
        std::cout << "Copy: " << copy1;
        
        std::cout << "\nAssignment operator:" << std::endl;
        ShrubberyCreation assign1("different1");
        assign1 = original1;
        
        std::cout << "Original: " << original1;
        std::cout << "Assigned: " << assign1;
        
        // Test if copy can be executed
        std::cout << "\nCan we execute the copy?" << std::endl;
        boss.executeForm(copy1);
        
    } catch (std::exception& e) {
        std::cout << "Uh oh, copy test exception: " << e.what() << std::endl;
    }
    
    return 0;
}
