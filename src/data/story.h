#pragma once

#include "issue.h"

// 3. Inheritance - The Story class inherits from the Issue class. The Story
// class is a child of the Issue class and the Issue class is the parent of
// the Story class.
class Story : public Issue
{
public:
    // 2. Encapsulation - The Story constructor is public so it can be called
    // from outside the class.
    // 8. Constructors - The Story constructor is used to initialize the
    // title, description and status properties.
    Story(std::string title, std::string description, IssueStatus status);

    // 2. Encapsulation - The print method is public so it can be called
    // from outside the class.
    // 4. Polymorphic Behaviour - The print method is overridden so it's
    // behaviour is different to the Issue class.
    void print() override;
};