#include "issue.h"

Issue::Issue(std::string title, std::string description, IssueStatus status, IssueType type) {
    this->title = title;
    this->description = description;
    this->status = status;
    this->type = type;
}