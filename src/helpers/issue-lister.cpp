#include "issue-lister.h"

// 1. Abstraction - The openIssuePredicate method is used to abstract the
// logic for filtering issues by status.
bool openIssuePredicate(Issue *issue)
{
    return issue->getStatus() != IssueStatus::developed || issue->getStatus() != IssueStatus::released;
}

// 8. Constructors - The IssueLister constructor is used to initialize the
// repository property.
IssueLister::IssueLister(IssueRepository *repository)
{
    this->repository = repository;
}

// 1. Abstraction - The listOpenIssues method is used to abstract the logic
// for filtering issues by status and printing them to the console.
void IssueLister::listOpenIssues()
{
    int filteredSize = 0;

    // 10. Functional Pointers - A functional pointer is used here so that the
    // issues can be filtered by a predicate. The predicate is a function is
    // ran for each item in the issues array and returns true or false . If the
    // predicate returns true, the issue is added to the result array.
    Issue **issues = this->repository->getIssues(filteredSize, *openIssuePredicate);

    for (int i = 0; i < filteredSize; i++)
    {
        // 4. Polymorphic Behaviour - The print method is called on the Issue
        // pointer. The print method is overridden in all subclasses of Issue
        // so the behaviour is different depending on the type of issue.
        issues[i]->print();
    }
}

// 1. Abstraction - The listAllIssues method is used to abstract the logic
// for printing all issues to the console.
void IssueLister::listAllIssues()
{
    // 9. Pointers - The issues array is a pointer to an array of Issue pointers.
    Issue **issues = this->repository->getIssues();

    for (int i = 0; i < this->repository->getSize(); i++)
    {
        // 4. Polymorphic Behaviour - The print method is called on the Issue
        // pointer. The print method is overridden in all subclasses of Issue
        // so the behaviour is different depending on the type of issue.
        issues[i]->print();
    }
}
