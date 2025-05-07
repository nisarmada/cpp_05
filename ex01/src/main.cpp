
#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

void testFormSigning() {
    std::cout << "\n==== TESTING FORM SIGNING ====\n";

    // Create bureaucrats with different grades
    Bureaucrat highRank("High Rank", 1);
    Bureaucrat midRank("Mid Rank", 50);
    Bureaucrat lowRank("Low Rank", 150);

    // Create forms with different grade requirements
    Form important("Important Form", 1, 1);
    Form standard("Standard Form", 50, 50);
    Form trivial("Trivial Form", 150, 150);

    // Test signing with different combinations
    std::cout << "\n--- Successful signing ---\n";
    highRank.signForm(important);  // Should succeed
    midRank.signForm(standard);    // Should succeed
    lowRank.signForm(trivial);     // Should succeed

    std::cout << "\n--- Failed signing ---\n";
    midRank.signForm(important);   // Should fail (grade too low)
    lowRank.signForm(standard);    // Should fail (grade too low)

    std::cout << "\n--- Edge cases ---\n";
    try {
        Form invalidHigh("Invalid High", 0, 1);  // Should throw
    } catch (const Form::GradeTooHighException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Form invalidLow("Invalid Low", 151, 1);  // Should throw
    } catch (const Form::GradeTooLowException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void testFormOutput() {
    std::cout << "\n==== TESTING FORM OUTPUT ====\n";
    Form testForm("Test Form", 42, 42);
    std::cout << testForm << std::endl;  // Test operator<< overload

    Bureaucrat bob("Bob", 42);
    bob.signForm(testForm);
    std::cout << "After signing:\n" << testForm << std::endl;
}

void testCopyAndAssignment() {
    std::cout << "\n==== TESTING COPY/ASSIGNMENT ====\n";
    Form original("Original", 30, 30);
    Bureaucrat clerk("Clerk", 30);
    clerk.signForm(original);

    Form copy(original);
    Form assigned;
    assigned = original;

    std::cout << "Original: " << original << "\n";
    std::cout << "Copy: " << copy << "\n";
    std::cout << "Assigned: " << assigned << "\n";
}

int main() {
    try {
        testFormSigning();
        testFormOutput();
        testCopyAndAssignment();
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}