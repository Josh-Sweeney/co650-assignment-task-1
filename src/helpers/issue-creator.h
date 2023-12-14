#pragma once

#include "../data/issue.h"
#include "../data/story.h"
#include "../data/bug.h"
#include "../data/epic.h"
#include "../data/issue-status.h"
#include "../data/issue-type.h"

#include <iostream>

// 1. Abstraction - The IssueCreator class is used to abstract the 
// process of creating Issues. This is to simplify and reduce the
// amount of code within the main function to handle this.
class IssueCreator {
    private:
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
        // title, description, status and type properties.
        IssueCreator();

        // 1. Abstraction - The createIssue method is used to abstract the process
        // of creating an Issue.
        // 4. Polymorphic Behaviour - The return type of the createIssue method is
        // an Issue pointer. This means that the method can return a pointer to an
        // Issue or any of it's subclasses (Story, Bug or Epic).
        // 9. Pointers - The createIssue method returns a pointer to an Issue.
        Issue* createIssue();
};