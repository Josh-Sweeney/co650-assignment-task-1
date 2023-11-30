#include "epic.h"

Epic::Epic(std::string title, std::string description, IssueStatus status) : Issue(title, description, status, IssueType::epic) { }

void Epic::print() {
    std::cout << "[" << statusToString(this->status) << "]" << " 📕 " << this->title << " - " << this->description << std::endl;
}