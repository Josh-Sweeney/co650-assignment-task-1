#pragma once

#include <iostream>

#include "issue-status.h"
#include "issue-type.h"

class Issue {
    public:
        std::string title;
        std::string description;
        IssueStatus status;
        IssueType type;

    protected:
        Issue(std::string title, std::string description, IssueStatus status, IssueType type);
};