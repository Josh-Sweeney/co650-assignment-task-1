#pragma once

#include <string>
#include <iostream>
#include "../data/issue-status.h"
#include "../data/issue-type.h"

// 1. Abstraction - The IssuePrompter class is used to abstract the process
// of prompting the user for Issue details. This is to simplify and reduce the
// amount of code within the main function to handle this.
class IssuePrompter
{
public:
    // 1. Abstraction - The promptIssueTitle method is used to abstract the process
    // of prompting the user for the status of the Issue.
    // 7. Static Members - The promptIssueStatus method is static as it does not
    // require an instance of the IssuePrompter class to be called.
    static IssueStatus promptIssueStatus();

    // 1. Abstraction - The promptIssueDescription method is used to abstract the process
    // of prompting the user for the type of the Issue.
    // 7. Static Members - The promptIssueType method is static as it does not
    // require an instance of the IssuePrompter class to be called.
    static IssueType promptIssueType();

    // 1. Abstraction - The promptIssueStatus method is used to abstract the process
    // of prompting the user for the title of the Issue.
    // 7. Static Members - The promptIssueTitle method is static as it does not
    // require an instance of the IssuePrompter class to be called.
    static std::string promptIssueTitle();

    // 1. Abstraction - The promptIssueDescription method is used to abstract the process
    // of prompting the user for the description of the Issue.
    // 7. Static Members - The promptIssueDescription method is static as it does not
    // require an instance of the IssuePrompter class to be called.
    static std::string promptIssueDescription();
};