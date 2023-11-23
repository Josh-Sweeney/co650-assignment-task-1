#include "issue.h"

std::string Issue::statusToString(IssueStatus status)
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

std::string Issue::typeToString(IssueType type)
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

void Issue::print()
{
    std::cout << "Title: " << this->title << std::endl;
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Status: " << statusToString(this->status) << std::endl;
    std::cout << "Type: " << typeToString(this->type) << std::endl;
}

Issue::Issue(std::string title, std::string description, IssueStatus status, IssueType type)
{
    this->title = title;
    this->description = description;
    this->status = status;
    this->type = type;
}