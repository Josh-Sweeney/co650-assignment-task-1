#include "story.h"

Story::Story(std::string title, std::string description, IssueStatus status) : Issue(title, description, status, IssueType::story) { }