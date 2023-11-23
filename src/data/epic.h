#include "issue.h"

#include <iostream>

class Epic : public Issue {
    public:
        Epic(std::string title, std::string description, IssueStatus status);
};