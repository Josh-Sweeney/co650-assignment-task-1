#pragma once

#include <iostream>

#include "issue-status.h"
#include "issue-type.h"

class Issue
{
public:
    // 4. Polymorphic Behaviour - The print method is a virtual method that
    // is intended to be overridden by subclasses. The print method is used
    // to print the issue to the console.
    virtual void print();

    // 2. Encapsulation - The title, description, status and type properties
    // are protected meaning the properties can only be read and set within
    // subclasses. Other classes can only read the values through the following
    // getter methods
    std::string getTitle();
    std::string getDescription();
    IssueStatus getStatus();
    IssueType getType();

protected:
    // 2. Encapsulation - The title, description, status and type properties
    // are protected and can only be read and set within subclasses.
    std::string title;
    std::string description;
    IssueStatus status;
    IssueType type;
    
    // 8. Constructors - The Issue constructor is used to initialize the
    // title, description, status and type properties. There is no public
    // constructor for the Issue class because it is an abstract class that
    // is intended to act as a base class.
    Issue(std::string title, std::string description, IssueStatus status, IssueType type);

private:
    // 1. Abstraction - The statusToString and typeToString functions are
    // abstracted away from the Issue class so that the Issue class does not
    // need to know how to convert the status and type properties to a string.
    // 6. Friendship - The statusToString and typeToString functions are friends
    // of the Issue class so that they can access the private status and type
    // properties.
    // 7. Static Members - The statusToString and typeToString functions are
    // static so that they can be called without an instance of the Issue class.
    static friend std::string statusToString(IssueStatus status);
    static friend std::string typeToString(IssueType type);
};

std::string statusToString(IssueStatus status)
{
    switch (status)
    {
    case IssueStatus::none:
        return "None";
    case IssueStatus::requirements:
        return "Requirements";
    case IssueStatus::backlog:
        return "Backlog";
    case IssueStatus::inDevelopment:
        return "In Development";
    case IssueStatus::developed:
        return "Developed";
    case IssueStatus::uat:
        return "UAT";
    case IssueStatus::released:
        return "Released";
    default:
        return "None";
    }
}

std::string typeToString(IssueType type)
{
    switch (type)
    {
    case IssueType::none:
        return "None";
    case IssueType::story:
        return "Story";
    case IssueType::bug:
        return "Bug";
    case IssueType::epic:
        return "Epic";
    default:
        return "None";
    }
}
