#include "data/issue-type.h"
#include "helpers/issue-creator.h"

#include "domain/issue-repository.h"

#include <windows.h>
#include <iostream>
#include <vector>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    IssueCreator creator;

    IssueRepository repository = IssueRepository();

    do {
        std::cout << "Select an option" << std::endl;
        std::cout << "1. Create new issue" << std::endl;
        std::cout << "2. List issues" << std::endl;

        std::string cinResult = "";
        std::cin >> cinResult;

        if (cinResult == "1") {
            repository.addIssue(creator.createIssue());
        } else if (cinResult == "2") {
            Issue** issues = repository.getIssues();

            for (int i = 0; i < repository.getSize(); i++) {
                issues[i]->print();
            }
        }
    } while (true);

    return 0;
}