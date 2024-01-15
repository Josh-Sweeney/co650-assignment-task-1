#include "issue-remover.h"

// 1. Abstraction - The closedIssuePredicate function is used to abstract the logic
// for filtering issues by status.
// 9. Pointers - The closedIssuePredicate takes an Issue pointer as an argument.
bool closedIssuePredicate(Issue *issue)
{
    return issue->getStatus() == IssueStatus::developed || issue->getStatus() == IssueStatus::released;
}

// 8. Constructors - The IssueRemover constructor is used to initialize the
// repository property.
// 9. Pointers - The IssueRemover constructor accepts a pointer to an IssueRepository.
IssueRemover::IssueRemover(IssueRepository *repository)
{
    this->repository = repository;
}

// 1. Abstraction - The removeClosedIssues method is used to abstract the logic
// for removing closed issues from the repository.
void IssueRemover::removeClosedIssues()
{
    int filteredSize = 0;

    // 9. Pointers - The getIssues returns a pointer to an array of Issue pointers.
    // The filteredSize argument is passed by reference and is used to return the
    // size of the filtered array.
    // 10. Functional Pointers - A functional pointer is used here to get all
    // issues that are closed using the closedIssuePredicate function.
    Issue **issues = this->repository->getIssues(filteredSize, *closedIssuePredicate);

    std::cout << "Removing the following issues: " << std::endl;

    for (int i = 0; i < filteredSize; i++)
    {
        issues[i]->print();
    }

    for (int i = 0; i < filteredSize; i++)
    {
        this->repository->removeIssue(issues[i]);
    }

    std::cout << "Issues removed." << std::endl;
}

// 1. Abstraction - The getIssueToRemove method is used to abstract the logic
// for getting the index of the issue to remove from the user. This logic
// includes printing the results to the screen and parsing the user input.
int IssueRemover::getIssueToRemove()
{
    std::string cinResult = "";
    int result = 0;

    Issue **issues = this->repository->getIssues();
    int numberOfIssues = this->repository->getSize();

    do
    {
        for (int i = 0; i < numberOfIssues; i++)
        {
            std::cout << i + 1 << ". ";
            issues[i]->print();
        }

        std::cout << "Enter the number of the issue you would like to remove: " << std::endl;
        std::cout << "Enter 0 to cancel: " << std::endl;
        std::cin >> cinResult;

        try
        {
            int result = std::stoi(cinResult);

            if (result < 0 || result > numberOfIssues)
            {
                throw std::invalid_argument("");
            }

            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "Invalid input. Please enter a number between 0 and " << numberOfIssues << ". " << std::endl;
            continue;
        }

    } while (result < 0 || result > numberOfIssues);

    result = std::stoi(cinResult);

    return result;
}

// 1. Abstraction - The removeIssues method is used to abstract the logic
// for removing chosen issues from the repository.
void IssueRemover::removeIssues()
{
    int result = 0;

    do
    {
        result = this->getIssueToRemove();

        if (result == 0)
        {
            return;
        }

        this->repository->removeIssue(result - 1); // Account for 0 indexing

    } while (result != 0);
}