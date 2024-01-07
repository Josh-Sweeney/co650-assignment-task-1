#include "issue-editor.h"

// 8. Constructors - The IssueEditor constructor is used to initialize the
// repository property.
IssueEditor::IssueEditor(IssueRepository *repository)
{
    this->repository = repository;
}

// 1. Abstraction - The getIssueToEdit method is used to abstract the logic
// for getting the issue to edit from the user. This logic
// includes printing the issues to the screen and parsing the user input.
// 9. Pointers - The getIssueToEdit method returns a pointer to an Issue.
Issue *IssueEditor::getIssueToEdit()
{
    std::string cinResult = "";
    int result = 0;

    Issue **issues = this->repository->getIssues();
    int numberOfIssues = this->repository->getSize();

    do
    {
        for (int i = 0; i < numberOfIssues; i++)
        {
            std::cout << i + 1 << ". ";
            issues[i]->print();
        }

        std::cout << "Enter the number of the issue you would like to edit: " << std::endl;
        std::cin >> cinResult;

        try
        {
            int result = std::stoi(cinResult);

            if (result <= 0 || result > numberOfIssues)
            {
                throw std::invalid_argument("");
            }

            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "Invalid input. Please enter a number between 1 and " << numberOfIssues << ". " << std::endl;
            continue;
        }

    } while (result <= 0 || result > numberOfIssues);

    result = std::stoi(cinResult);

    return issues[result - 1];
}

// 1. Abstraction - The changeIssueStatus method is used to abstract the logic
// for editing an issue.
// 9. Pointers - The changeIssueStatus uses the getIssueToEdit method to get
// a pointer to the issue to edit. This pointer is then used to edit the issue
// directly.
void IssueEditor::changeIssueStatus()
{
    // Because this returns a pointer to the original issue, we can edit it directly
    // without the need for a updateIssue method.
    Issue *issue = this->getIssueToEdit();

    // 7. Static Members - The promptIssueStatus method is a static member of
    // the IssuePrompter class and can be called without an instance of the
    // IssuePrompter class.
    IssueStatus newStatus = IssuePrompter::promptIssueStatus();

    issue->setStatus(newStatus);
}

// 1. Abstraction - The changeIssueType method is used to abstract the logic
// for editing an issue.
// 9. Pointers - The changeIssueType uses the getIssueToEdit method to get
// a pointer to the issue to edit. Since the type of the Issue class cannot be
// changed, the issue is removed from the repository and a new issue is added
// with the same title, description and status but with a different type.
void IssueEditor::changeIssueType()
{
    Issue *issue = this->getIssueToEdit();

    // 7. Static Members - The promptIssueType method is a static member of
    // the IssuePrompter class and can be called without an instance of the
    // IssuePrompter class.
    IssueType newType = IssuePrompter::promptIssueType();

    this->repository->removeIssue(issue);

    switch (newType)
    {
    case IssueType::story:
        this->repository->addIssue(new Story(issue->getTitle(), issue->getDescription(), issue->getStatus()));
        break;
    case IssueType::bug:
        this->repository->addIssue(new Bug(issue->getTitle(), issue->getDescription(), issue->getStatus()));
        break;
    case IssueType::epic:
        this->repository->addIssue(new Epic(issue->getTitle(), issue->getDescription(), issue->getStatus()));
        break;
    }
}

// 1. Abstraction - The changeIssueTitle method is used to abstract the logic
// for editing an issue.
// 9. Pointers - The changeIssueTitle uses the getIssueToEdit method to get
// a pointer to the issue to edit. This pointer is then used to edit the issue
// directly.
void IssueEditor::changeIssueTitle()
{
    // Because this returns a pointer to the original issue, we can edit it directly
    // without the need for a updateIssue method.
    Issue *issue = this->getIssueToEdit();

    // This is required to clear the input buffer before calling getline
    std::cin.ignore();

    // 7. Static Members - The promptIssueTitle method is a static member of
    // the IssuePrompter class and can be called without an instance of the
    // IssuePrompter class.
    std::string newTitle = IssuePrompter::promptIssueTitle();

    issue->setTitle(newTitle);
}

// 1. Abstraction - The changeIssueDescription method is used to abstract the logic
// for editing an issue.
// 9. Pointers - The changeIssueDescription uses the getIssueToEdit method to get
// a pointer to the issue to edit. This pointer is then used to edit the issue
// directly.
void IssueEditor::changeIssueDescription()
{
    // Because this returns a pointer to the original issue, we can edit it directly
    // without the need for a updateIssue method.
    Issue *issue = this->getIssueToEdit();

    // This is required to clear the input buffer before calling getline
    std::cin.ignore();

    // 7. Static Members - The promptIssueDescription method is a static member of
    // the IssuePrompter class and can be called without an instance of the
    // IssuePrompter class.
    std::string newDescription = IssuePrompter::promptIssueDescription();

    issue->setDescription(newDescription);
}