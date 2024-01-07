#include "data/issue-type.h"

#include "helpers/issue-creator.h"
#include "helpers/issue-lister.h"
#include "helpers/issue-remover.h"


#include "domain/issue-repository.h"

#include <windows.h>
#include <iostream>
#include <vector>
#include <istream>
#include <string>

// 1. Abstraction - The IssueRepository class is used to abstract the process
// of storing, retrieving and manipulating Issues.
IssueRepository repository = IssueRepository();

// 1. Abstraction - The IssueCreator class is used to abstract the process
// of creating Issues. This is to simplify and reduce the
// amount of code within the main function to handle this.
IssueCreator issueCreator = IssueCreator(&repository);

// 1. Abstraction - The IssueLister class is used to abstract the process
// of listing Issues. This is to simplify and reduce the
// amount of code within the main function to handle this.
IssueLister issueLister = IssueLister(&repository);

// 1. Abstraction - The IssueRemover class is used to abstract the process
// of removing Issues. This is to simplify and reduce the
// amount of code within the main function to handle this.
IssueRemover issueRemover = IssueRemover(&repository);

// 1. Abstraction - The printOptions method is used to abstract the logic for
// printing the options to the console.
void printOptions()
{
    std::cout << "Select an option" << std::endl;
    std::cout << "1. Create new issue" << std::endl;
    std::cout << "2. List issues" << std::endl;
    std::cout << "3. List open issues" << std::endl;
    std::cout << "4. Remove issues" << std::endl;
    std::cout << "5. Remove closed issues" << std::endl;
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
            issueCreator.createIssue();
            break;
        case 2:
            issueLister.listAllIssues();
            break;
        case 3:
            issueLister.listOpenIssues();
            break;
        case 4:
            issueRemover.removeIssues();
            break;
        case 5:
            issueRemover.removeClosedIssues();
            break;
        default:
            std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
            continue;
        }
    } while (true);

    return 0;
}
