#include "../domain/issue-repository.h"
#include "../data/issue.h"

#include <string>

// 1. Abstraction - The IssueRemover class is used to abstract the process
// of removing Issues. This is to simplify and reduce the
// amount of code within the main function to handle this.
class IssueRemover
{
private:
    // 1. Abstraction - The IssueRepository class is used to abstract the process
    // of retrieving and removing Issues.
    IssueRepository *repository;

    // 1. Abstraction - The getIssueToRemove method is used to abstract the logic
    // for getting the index of the issue to remove from the user. This logic
    // includes printing the results to the screen and parsing the user input.
    int getIssueToRemove();

public:
    // 8. Constructors - The IssueRemover constructor is used to initialize the
    // repository property.
    IssueRemover(IssueRepository *repository);

    // 1. Abstraction - The removeIssues method is used to abstract the logic
    // for removing chosen issues from the repository.
    void removeIssues();

    // 1. Abstraction - The removeClosedIssues method is used to abstract the logic
    // for removing closed issues from the repository.
    void removeClosedIssues();
};