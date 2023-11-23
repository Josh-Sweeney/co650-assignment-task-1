#pragma once

#include <iostream>

#include "issue-status.h"
#include "issue-type.h"

class Issue
{
public:
    void print();

protected:
    std::string title;
    std::string description;
    IssueStatus status;
    IssueType type;

    // TODO: Consider if this is appropriate here
    static std::string statusToString(IssueStatus status);
    static std::string typeToString(IssueType type);

    Issue(std::string title, std::string description, IssueStatus status, IssueType type);
};