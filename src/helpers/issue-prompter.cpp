#include "issue-prompter.h"

// 1. Abstraction - The promptIssueStatus method abstracts the logic for
// displaying the issue status options, prompting the user to select
// an option, parsing the result and error handling.
IssueStatus IssuePrompter::promptIssueStatus() {
    std::string cinResult = "";
    int result = 0;

    do {
        std::cout << "Enter status (1-6): " << std::endl;
        std::cout << "\t1. Requirements" << std::endl;
        std::cout << "\t2. Backlog" << std::endl;
        std::cout << "\t3. In Development" << std::endl;
        std::cout << "\t4. Developed" << std::endl;
        std::cout << "\t5. UAT" << std::endl;
        std::cout << "\t6. Released" << std::endl;

        std::cin >> cinResult;

        try {
            int result = std::stoi(cinResult);

            if (result < 0 || result > 6) {
                throw std::invalid_argument("Invalid input. Please enter a number between 1 and 6.");
            }

            break;

        } catch (std::invalid_argument& e) {
            std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
            continue;
        }
    } while (result <= 0 || result > 6);

    result = std::stoi(cinResult);

    return (IssueStatus)result;
}

// 1. Abstraction - The promptIssueType method abstracts the logic for
// displaying the issue type options, prompting the user to select
// an option, parsing the result and error handling.
IssueType IssuePrompter::promptIssueType() {
    std::string cinResult = "";
    int result = 0;

    do {
        std::cout << "Enter type (1-3): " << std::endl;
        std::cout << "\t1. Story" << std::endl;
        std::cout << "\t2. Bug" << std::endl;
        std::cout << "\t3. Epic" << std::endl;

        std::cin >> cinResult;

        try {
            int result = std::stoi(cinResult);

            if (result < 0 || result > 3) {
                throw std::invalid_argument("Invalid input. Please enter a number between 1 and 3.");
            }

            break;

        } catch (std::invalid_argument& e) {
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
            continue;
        }

    } while (result <= 0 || result > 3);

    result = std::stoi(cinResult);

    return (IssueType)result;
}

// 1. Abstraction - The promptIssueTitle method abstracts the logic for
// prompting the user to enter the title of the issue.
std::string IssuePrompter::promptIssueTitle()
{
    std::string title;

    std::cout << "Enter title: " << std::endl;
    std::getline(std::cin, title);

    return title;
}

// 1. Abstraction - The promptIssueDescription method abstracts the logic for
// prompting the user to enter the description of the issue.
std::string IssuePrompter::promptIssueDescription()
{
    std::string description;

    std::cout << "Enter description: " << std::endl;
    std::getline(std::cin, description);

    return description;
}
