#include "epic.h"

Epic::Epic(std::string title, std::string description, IssueStatus status) : Issue(title, description, status, IssueType::epic) { }