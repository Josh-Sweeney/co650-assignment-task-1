#include "data/issue-type.h"
#include "helpers/issue-creator.h"

#include <windows.h>
#include <iostream>
#include <vector>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    IssueCreator creator;

    std::vector<std::shared_ptr<Issue>> issues;
    issues.push_back(std::make_shared<Bug>(Bug("Bug 1", "Bug 1 description", IssueStatus::backlog)));
    issues.push_back(std::make_shared<Story>(Story("Story 1", "Story 1 description", IssueStatus::inDevelopment)));
    issues.push_back(std::make_shared<Epic>(Epic("Epic 1", "Epic 1 description", IssueStatus::developed)));

    do {
        std::cout << "Select an option" << std::endl;
        std::cout << "1. Create new issue" << std::endl;
        std::cout << "2. List issues" << std::endl;

        std::string cinResult = "";
        std::cin >> cinResult;

        if (cinResult == "1") {
            issues.push_back(creator.createIssue());
        } else if (cinResult == "2") {
            for (const auto& issue : issues) {
                issue->print();
            }
        }
    } while (true);

    return 0;
}