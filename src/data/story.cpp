#include "story.h"

Story::Story(std::string title, std::string description, IssueStatus status) : Issue(title, description, status, IssueType::story) {}

void Story::print() {
    std::cout << "[" << statusToString(this->status) << "]" << " 📗 " << this->title << " - " << this->description << std::endl;
}