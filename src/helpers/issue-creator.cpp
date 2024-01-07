#include "issue-creator.h"

// 8. Constructors - The IssueCreator constructor is used to initialize the
// title, description, status and type properties. The constructor accepts
// an IssueRepository pointer which is used to add the created Issue to the
// repository.
IssueCreator::IssueCreator(IssueRepository* repository) {
    this-> repository = repository;

    this->title = "";
    this->description = "";
    this->status = IssueStatus::none;
    this->type = IssueType::none;
}

// 1. Abstraction - The createIssue method is used to abstract the process
// of creating an Issue.
// 4. Polymorphic Behaviour - This method determines the type of Issue to
// create through user input and then initialises either a Bug, Story or Epic
// which is a subclass of Issue and then adds it to the repository using
// the addIssue method which accepts an Issue pointer.
// 9. Pointers - The addIssue method accepts a pointer to an Issue.
void IssueCreator::createIssue() {
    // This is required to clear the input buffer before calling getline
    std::cin.ignore();

    // 7. Static Members - The IssuePrompter provides the following static methods
    // to prompt the user for the relevant information without requiring an
    // instance of the IssuePrompter class
    this->title = IssuePrompter::promptIssueTitle();
    this->description = IssuePrompter::promptIssueDescription();
    this->status = IssuePrompter::promptIssueStatus();
    this->type = IssuePrompter::promptIssueType();

    Issue* issue;

    if (this->type == IssueType::bug) {
        issue = new Bug(this->title, this->description, this->status);
    } else if (this->type == IssueType::story) {
        issue = new Story(this->title, this->description, this->status);
    } else if (this->type == IssueType::epic) {
        issue = new Epic(this->title, this->description, this->status);
    }

    this->repository->addIssue(issue);
};