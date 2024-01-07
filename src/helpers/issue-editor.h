#pragma once

#include <string>

#include "issue-prompter.h"

#include "../domain/issue-repository.h"

// 1. Abstraction - The IssueEditor class is used to abstract the process
// of editing Issues. This is to simplify and reduce the
// amount of code within the main function to handle this.
class IssueEditor {
    private:
        // 1. Abstraction - The IssueRepository class is used to abstract the process
        // of retrieving and editing Issues.
        // 9. Pointers - The IssueRepository property is a pointer to an IssueRepository.
        IssueRepository *repository;

        // 1. Abstraction - The getIssueToEdit method is used to abstract the logic
        // for getting the issue to edit from the user. This logic
        // includes printing the issues to the screen and parsing the user input.
        Issue* getIssueToEdit();

    public:
        // 8. Constructors - The IssueEditor constructor is used to initialize the
        // repository property.
        // 9. Pointers - The IssueEditor constructor accepts a pointer to an IssueRepository.
        IssueEditor(IssueRepository *repository);

        // 1. Abstraction - The changeIssueStatus method is used to abstract the logic
        // for editing an issue.
        void changeIssueStatus();

        // 1. Abstraction - The changeIssueType method is used to abstract the logic
        // for editing an issue.
        void changeIssueType();

        // 1. Abstraction - The changeIssueTitle method is used to abstract the logic
        // for editing an issue.
        void changeIssueTitle();

        // 1. Abstraction - The changeIssueDescription method is used to abstract the logic
        // for editing an issue.
        void changeIssueDescription();
};