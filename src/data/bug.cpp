#include "bug.h"

Bug::Bug(std::string title, std::string description, IssueStatus status) : Issue(title, description, status, IssueType::bug) { }

void Bug::print() {
    std::cout << "[" << statusToString(this->status) << "]" << " 📘 " << this->title << " - " << this->description << std::endl;
}