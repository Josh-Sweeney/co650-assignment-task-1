#include "issue.h"


void Issue::print()
{
    std::cout << "Title: " << this->title << std::endl;
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Status: " << statusToString(this->status) << std::endl;
    std::cout << "Type: " << typeToString(this->type) << std::endl;
}

std::string Issue::getTitle()
{
    return this->title;
}

std::string Issue::getDescription()
{
    return this->description;
}

IssueStatus Issue::getStatus()
{
    return this->status;
}

IssueType Issue::getType()
{
    return this->type;
}

Issue::Issue(std::string title, std::string description, IssueStatus status, IssueType type)
{
    this->title = title;
    this->description = description;
    this->status = status;
    this->type = type;
}