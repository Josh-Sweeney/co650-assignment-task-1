#include "data/issue-type.h"
#include "helpers/issue-creator.h"

#include "domain/issue-repository.h"

#include <windows.h>
#include <iostream>
#include <vector>

IssueRepository repository = IssueRepository();

void printOptions()
{
    std::cout << "Select an option" << std::endl;
    std::cout << "1. Create new issue" << std::endl;
    std::cout << "2. List issues" << std::endl;
    std::cout << "3. List open issues" << std::endl;
}

int getInput()
{
    int num;
    std::cin >> num;

    if (std::cin.fail())
    {
        std::cout << "Input was not a number." << std::endl;
        return 0;
    }

    return num;
}

void addNewIssue()
{
    IssueCreator creator;
    repository.addIssue(creator.createIssue());
}

void listAllIssues()
{
    Issue **issues = repository.getIssues();

    for (int i = 0; i < repository.getSize(); i++)
    {
        issues[i]->print();
    }
}

void listOpenIssues()
{
    int filteredSize = 0;

    Issue **issues = repository.getIssues(filteredSize, [](Issue *issue)
                                          {
        switch(issue->getStatus()) {
            case IssueStatus::developed:
            case IssueStatus::released:
                return false;
            default:
                return true;
        } });

    for (int i = 0; i < filteredSize; i++)
    {
        issues[i]->print();
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    do
    {
        printOptions();
        int option = getInput();

        switch (option)
        {
        case 1:
            addNewIssue();
            break;
        case 2:
            listAllIssues();
            break;
        case 3:
            listOpenIssues();
            break;
        default:
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
            continue;
        }
    } while (true);

    return 0;
}
