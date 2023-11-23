#include "issue-creator.h"
#include <string>

IssueCreator::IssueCreator() {
    this->title = "";
    this->description = "";
    this->status = IssueStatus::none;
    this->type = IssueType::none;
}

void IssueCreator::promptIssueStatus() {
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

    this->status = (IssueStatus)result;
}

void IssueCreator::promptIssueType() {
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

    this->type = (IssueType)result;
}

Issue IssueCreator::createIssue() {
    std::cout << "Enter title: ";
    std::cin >> this->title;

    std::cout << "Enter description: ";
    std::cin >> this->description;

    promptIssueStatus();
    promptIssueType();

    if (this->type == IssueType::bug) {
        return Bug(this->title, this->description, this->status);
    } else if (this->type == IssueType::story) {
        return Story(this->title, this->description, this->status);
    } else if (this->type == IssueType::epic) {
        return Epic(this->title, this->description, this->status);
    }

    // TODO: Throw exception
};