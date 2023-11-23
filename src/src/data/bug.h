#include "issue.h"

#include <iostream>

class Bug : public Issue {
    public:
        Bug(std::string title, std::string description, IssueStatus status);
};