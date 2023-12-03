#include "issue-repository.h"

IssueRepository::IssueRepository()
{
    this->issues = new Issue *[0];
    this->size = 0;

    addIssue(new Bug("Bug 1", "Bug 1 description", IssueStatus::backlog));
    addIssue(new Bug("Bug 2", "This is a closed bug", IssueStatus::developed));
    addIssue(new Story("Story 1", "Story 1 description", IssueStatus::inDevelopment));
    addIssue(new Story("Story 2", "This is a closed story", IssueStatus::released));
    addIssue(new Epic("Epic 1", "Epic 1 description", IssueStatus::developed));
}

Issue **IssueRepository::getIssues()
{
    return this->issues;
}

// Filter issues by predicate and set size to the number of issues that match the predicate
Issue **IssueRepository::getIssues(int& size, bool (*predicate)(Issue *))
{
    Issue **result = new Issue *[this->size];
    int resultIndex = 0;

    for (int i = 0; i < this->size; i++)
    {
        if (predicate(this->issues[i]))
        {
            result[resultIndex] = this->issues[i];
            resultIndex++;
        }
    }

    size = resultIndex;

    return result;
}

int IssueRepository::getSize()
{
    return this->size;
}

void IssueRepository::addIssue(Issue *issue)
{
    Issue **newIssues = new Issue *[this->size + 1];

    for (int i = 0; i < this->size; i++)
    {
        newIssues[i] = this->issues[i];
    }

    newIssues[this->size] = issue;

    this->issues = newIssues;
    this->size++;
}