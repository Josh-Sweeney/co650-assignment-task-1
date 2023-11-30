#pragma once

#include "issue.h"

class Story : public Issue
{
public:
    Story(std::string title, std::string description, IssueStatus status);

    void print() override;
};