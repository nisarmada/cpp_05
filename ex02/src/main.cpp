#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreation.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <iostream>
#include <chrono>
#include <thread>

// Function to print a separator line for better output readability
void printSeparator() {
    std::cout << "\n----------------------------------------\n" << std::endl;
}

int main() {
    try {
        std::cout << "CREATING BUREAUCRATS WITH DIFFERENT GRADES" << std::endl;
        // Creating bureaucrats with different grades
        Bureaucrat boss("Big Boss", 1);           // Highest possible grade
        Bureaucrat manager("Manager", 30);        // Mid-high grade
        Bureaucrat employee("Employee", 60);      // Mid grade
        Bureaucrat intern("Intern", 140);         // Low grade
        
        // Print all bureaucrats to verify creation
        std::cout << boss << manager << employee << intern;
        
        printSeparator();
        
        std::cout << "TESTING SHRUBBERY CREATION FORM" << std::endl;
        // Create a ShrubberyCreation form
        ShrubberyCreation shrubForm("garden");
        std::cout << "Created: " << shrubForm;
        
        // Test signing with different bureaucrats
        std::cout << "\nIntern trying to sign (should succeed):" << std::endl;
        intern.signForm(shrubForm);
        
        // Try executing with different grades
        std::cout << "\nIntern trying to execute (should fail - too low grade):" << std::endl;
        intern.executeForm(shrubForm);
        
        std::cout << "\nEmployee trying to execute (should succeed):" << std::endl;
        employee.executeForm(shrubForm);
        
        printSeparator();
        
        std::cout << "TESTING ROBOTOMY REQUEST FORM" << std::endl;
        // Create a RobotomyRequestForm
        RobotomyRequestForm robotForm("subject");
        std::cout << "Created: " << robotForm;
        
        // Test signing with different bureaucrats
        std::cout << "\nIntern trying to sign (should fail - too low grade):" << std::endl;
        intern.signForm(robotForm);
        
        std::cout << "\nEmployee trying to sign (should succeed):" << std::endl;
        employee.signForm(robotForm);
        
        // Try executing with different grades
        std::cout << "\nEmployee trying to execute (should fail - too low grade):" << std::endl;
        employee.executeForm(robotForm);
        
        std::cout << "\nManager trying to execute (should succeed):" << std::endl;
        manager.executeForm(robotForm);
        
        // Execute it multiple times to test 50% success rate
        std::cout << "\nTesting robotomy multiple times:" << std::endl;
        for (int i = 0; i < 5; i++) {
            manager.executeForm(robotForm);
			 std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        
        printSeparator();
        
        std::cout << "TESTING PRESIDENTIAL PARDON FORM" << std::endl;
        // Create a PresidentialPardonForm
        PresidentialPardonForm pardonForm("criminal");
        std::cout << "Created: " << pardonForm;
        
        // Test signing with different bureaucrats
        std::cout << "\nManager trying to sign (should fail - too low grade):" << std::endl;
        manager.signForm(pardonForm);
        
        std::cout << "\nBoss trying to sign (should succeed):" << std::endl;
        boss.signForm(pardonForm);
        
        // Try executing with different grades
        std::cout << "\nManager trying to execute (should fail - too low grade):" << std::endl;
        manager.executeForm(pardonForm);
        
        std::cout << "\nBoss trying to execute (should succeed):" << std::endl;
        boss.executeForm(pardonForm);
        
        printSeparator();
        
        std::cout << "TESTING EXCEPTIONS" << std::endl;
        
        // Test executing unsigned form
        std::cout << "\nTrying to execute unsigned form:" << std::endl;
        RobotomyRequestForm unsignedForm("unsigned");
        boss.executeForm(unsignedForm);
        
        // Test trying to create an invalid bureaucrat
        std::cout << "\nTrying to create invalid bureaucrats:" << std::endl;
        std::cout << "Grade too high (0): ";
        Bureaucrat tooHigh("Too High", 0);
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test copying forms
    printSeparator();
    std::cout << "TESTING COPY CONSTRUCTORS AND ASSIGNMENT OPERATORS" << std::endl;
    
    try {
        // Original forms
        ShrubberyCreation original1("original1");
        RobotomyRequestForm original2("original2");
        PresidentialPardonForm original3("original3");
        
        // Sign an original to test if sign status is copied
        Bureaucrat boss("Copy Test Boss", 1);
        boss.signForm(original1);
        
        // Test copy constructor
        std::cout << "\nTesting copy constructor:" << std::endl;
        ShrubberyCreation copy1(original1);
        RobotomyRequestForm copy2(original2);
        PresidentialPardonForm copy3(original3);
        
        std::cout << "Original: " << original1;
        std::cout << "Copy: " << copy1;
        
        // Test assignment operator
        std::cout << "\nTesting assignment operator:" << std::endl;
        ShrubberyCreation assign1("different1");
        assign1 = original1;
        
        std::cout << "Original: " << original1;
        std::cout << "Assigned: " << assign1;
        
        // Test if copy can be executed
        std::cout << "\nTesting if copy can be executed:" << std::endl;
        boss.executeForm(copy1);
        
    } catch (std::exception& e) {
        std::cout << "Exception caught in copy test: " << e.what() << std::endl;
    }
    
    return 0;
}