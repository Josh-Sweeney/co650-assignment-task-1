#pragma once

#include "../data/issue.h"
#include "../data/story.h"
#include "../data/bug.h"
#include "../data/epic.h"
#include "../data/issue-status.h"
#include "../data/issue-type.h"

#include <iostream>

class IssueCreator {
    private:
        std::string title;
        std::string description;
        IssueStatus status;
        IssueType type;

        void promptIssueStatus();
        void promptIssueType();

    public:
        IssueCreator();

        Issue* createIssue();
};