#include "bug.h"

Bug::Bug(std::string title, std::string description, IssueStatus status) : Issue(title, description, status, IssueType::Bug) { }