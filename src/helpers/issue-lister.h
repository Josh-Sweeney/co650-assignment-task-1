#pragma once

#include "../domain/issue-repository.h"

// 1. Abstraction - The IssueLister class is used to abstract the process
// of listing Issues. This is to simplify and reduce the
// amount of code within the main function to handle this.
class IssueLister
{
private:
    // 1. Abstraction - The IssueRepository class is used to abstract the process
    // of retrieving Issues.
    IssueRepository *repository;

public:
    // 8. Constructors - The IssueLister constructor is used to initialize the
    // repository property.
    IssueLister(IssueRepository *repository);

    // 1. Abstraction - The listAllIssues method is used to abstract the logic
    // for printing all issues to the console.
    void listAllIssues();

    // 1. Abstraction - The listOpenIssues method is used to abstract the logic
    // for filtering issues by status and printing them to the console.
    void listOpenIssues();
};
