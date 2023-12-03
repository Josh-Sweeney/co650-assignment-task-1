#pragma once

#include <iostream>

#include "issue-status.h"
#include "issue-type.h"

class Issue
{
public:
    virtual void print();

    std::string getTitle();
    std::string getDescription();
    IssueStatus getStatus();
    IssueType getType();

protected:
    std::string title;
    std::string description;
    IssueStatus status;
    IssueType type;
    
    Issue(std::string title, std::string description, IssueStatus status, IssueType type);

private:
    // TODO: Consider if this is appropriate here
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
