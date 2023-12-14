#include "issue-repository.h"

// 8. Constructors - The IssueRepository constructor is used to initialize the
// issues array with some dummy data.
IssueRepository::IssueRepository()
{
    this->issues = new Issue *[0];
    this->size = 0;

    addIssue(new Bug("Bug 1", "Bug 1 description", IssueStatus::backlog));
    addIssue(new Bug("Bug 2", "This is a closed bug", IssueStatus::developed));
    addIssue(new Story("Story 1", "Story 1 description", IssueStatus::inDevelopment));
    addIssue(new Story("Story 2", "This is a closed story", IssueStatus::released));
    addIssue(new Epic("Epic 1", "Epic 1 description", IssueStatus::developed));
}

// 1. Abstraction - The getIssues method abstracts away the code required
// to filter the issues array.
// 2. Encapsulation - The issues array is private and can only be accessed
// through the getIssues method.
// 9. Pointers - The issues array is a pointer to an array of Issue pointers.
Issue **IssueRepository::getIssues()
{
    return this->issues;
}

// 1. Abstraction - The getIssues method abstracts away the code required
// to filter the issues array. This means that a user using the IssueRepository
// class does not need to know how to filter the issues array.
// 2. Encapsulation - The issues array is private and can only be accessed
// through the getIssues method.
// 5. Overloading - The getIssues method is overloaded so that it can be
// called with or without a predicate.
// 9. Pointers - The size parameter is a pointer so that the filtered size
// can be returned through the parameter.
// 10. Functional Pointers - A functional pointer is used here so that the 
// issues can be filtered by a predicate. The predicate is a function is
// ran for each item in the issues array and returns true or false . If the
Issue **IssueRepository::getIssues(int& filteredSize, bool (*predicate)(Issue *))
{
    Issue **result = new Issue *[this->size];
    int resultIndex = 0;

    for (int i = 0; i < this->size; i++)
    {
        if (predicate(this->issues[i]))
        {
            result[resultIndex] = this->issues[i];
            resultIndex++;
        }
    }

    filteredSize = resultIndex;

    return result;
}

// 2. Encapsulation - The size property is private and can only be accessed
// through the getSize method.
int IssueRepository::getSize()
{
    return this->size;
}

// 1. Abstraction - The addIssue method abstracts away the code required
// to add an issue to the issues array. This means that a user using the
// IssueRepository class does not need to know how to add an issue to the
// issues array.
// 2. Encapsulation - The issues array is private and can only be manipulated
// through the addIssue method.
// 9. Pointers - The issue parameter is a pointer to an Issue object and the
// issues array is a pointer to an array of Issue pointers.
void IssueRepository::addIssue(Issue *issue)
{
    Issue **newIssues = new Issue *[this->size + 1];

    for (int i = 0; i < this->size; i++)
    {
        newIssues[i] = this->issues[i];
    }

    newIssues[this->size] = issue;

    this->issues = newIssues;
    this->size++;
}