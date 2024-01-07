#pragma once

#include "../data/issue.h"
#include "../data/story.h"
#include "../data/bug.h"
#include "../data/epic.h"
#include "../data/issue-status.h"
#include "../data/issue-type.h"

#include <iostream>
#include "../domain/issue-repository.h"

// 1. Abstraction - The IssueCreator class is used to abstract the 
// process of creating Issues. This is to simplify and reduce the
// amount of code within the main function to handle this.
class IssueCreator {
    private:
        // 1. Abstraction - The IssueRepository class is used to abstract the process
        // of storing, retrieving and manipulating Issues.
        IssueRepository* repository;
        
        // 2. Encapsulation - The title property is private and can only be accessed
        // through the getTitle method.
        std::string title;

        // 2. Encapsulation - The description property is private and can only be accessed
        // through the getDescription method.
        std::string description;

        // 2. Encapsulation - The status property is private and can only be accessed
        // through the getStatus method.
        IssueStatus status;

        // 2. Encapsulation - The type property is private and can only be accessed
        // through the getType method.
        IssueType type;
        
        // 1. Abstraction - The promptIssueTitle method is used to abstract the process
        // of prompting the user for the status of the Issue.
        void promptIssueStatus();

        // 1. Abstraction - The promptIssueDescription method is used to abstract the process
        // of prompting the user for the type of the Issue.
        void promptIssueType();

    public:
        // 8. Constructors - The IssueCreator constructor is used to initialize the
        // title, description, status and type properties. The constructor accepts
        // an IssueRepository pointer which is used to add the created Issue to the
        // repository.
        IssueCreator(IssueRepository* repository);

        // 1. Abstraction - The createIssue method is used to abstract the process
        // of creating an Issue.
        // 4. Polymorphic Behaviour - This method determines the type of Issue to
        // create through user input and then initialises either a Bug, Story or Epic
        // which is a subclass of Issue and then adds it to the repository using
        // the addIssue method which accepts an Issue pointer.
        // 9. Pointers - The addIssue method accepts a pointer to an Issue.
        void createIssue();
};