#include "data/issue-type.h"
#include "helpers/issue-creator.h"

#include "domain/issue-repository.h"

#include <windows.h>
#include <iostream>
#include <vector>

IssueRepository repository = IssueRepository();

// 1. Abstraction - The printOptions method is used to abstract the logic for
// printing the options to the console.
void printOptions()
{
    std::cout << "Select an option" << std::endl;
    std::cout << "1. Create new issue" << std::endl;
    std::cout << "2. List issues" << std::endl;
    std::cout << "3. List open issues" << std::endl;
}

// 1. Abstraction - The getInput method is used to abstract the logic for
// getting input from the user.
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

// 1. Abstraction - The addNewIssue method is used to abstract the logic for
// creating a new issue and adding it to the repository.
void addNewIssue()
{
    IssueCreator creator;
    repository.addIssue(creator.createIssue());
}

// 1. Abstraction - The listAllIssues method is used to abstract the logic
// for printing all issues to the console.
void listAllIssues()
{
    // 9. Pointers - The issues array is a pointer to an array of Issue pointers.
    Issue **issues = repository.getIssues();

    for (int i = 0; i < repository.getSize(); i++)
    {
        // 4. Polymorphic Behaviour - The print method is called on the Issue
        // pointer. The print method is overridden in all subclasses of Issue
        // so the behaviour is different depending on the type of issue.
        issues[i]->print();
    }
}

// 1. Abstraction - The openIssuePredicate method is used to abstract the
// logic for filtering issues by status.
bool openIssuePredicate(Issue *issue)
{
    return issue->getStatus() != IssueStatus::developed || issue->getStatus() != IssueStatus::released;
}

// 1. Abstraction - The listOpenIssues method is used to abstract the logic
// for filtering issues by status and printing them to the console.
void listOpenIssues()
{
    int filteredSize = 0;

    // 10. Functional Pointers - A functional pointer is used here so that the
    // issues can be filtered by a predicate. The predicate is a function is
    // ran for each item in the issues array and returns true or false . If the
    // predicate returns true, the issue is added to the result array.
    Issue **issues = repository.getIssues(filteredSize, *openIssuePredicate);

    for (int i = 0; i < filteredSize; i++)
    {
        // 4. Polymorphic Behaviour - The print method is called on the Issue
        // pointer. The print method is overridden in all subclasses of Issue
        // so the behaviour is different depending on the type of issue.
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
