#include "issue.h"

// 1. Abstraction - The print method is abstract and must be implemented
// by subclasses.
// 4. Polymorphic Behaviour - The print method is a virtual method that
// is intended to be overridden by subclasses. The print method is used
// to print the issue to the console.
void Issue::print()
{
    std::cout << "Title: " << this->title << std::endl;
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Status: " << statusToString(this->status) << std::endl;
    std::cout << "Type: " << typeToString(this->type) << std::endl;
}

// 2. Encapsulation - The title property is protected and can only be read
// and set within subclasses. Other classes can only read the value through
// this getTitle method.
std::string Issue::getTitle()
{
    return this->title;
}

// 2. Encapsulation - The description property is protected and can only be read
// and set within subclasses. Other classes can only read the value through
// this getDescription method.
std::string Issue::getDescription()
{
    return this->description;
}

// 2. Encapsulation - The status property is protected and can only be read
// and set within subclasses. Other classes can only read the value through
// this getStatus method.
IssueStatus Issue::getStatus()
{
    return this->status;
}

// 2. Encapsulation - The type property is protected and can only be read
// and set within subclasses. Other classes can only read the value through
// this getType method.
IssueType Issue::getType()
{
    return this->type;
}

// 8. Constructors - The Issue constructor is used to initialize the
// title, description, status and type properties. There is no public
// constructor for the Issue class because it is an abstract class that
// is intended to act as a base class.
Issue::Issue(std::string title, std::string description, IssueStatus status, IssueType type)
{
    this->title = title;
    this->description = description;
    this->status = status;
    this->type = type;
}