#pragma once

#include "../data/issue.h"
#include "../data/bug.h"
#include "../data/epic.h"
#include "../data/story.h"


class IssueRepository {
  private:
    // std::vector<std::shared_ptr<Issue>> issues;
    Issue** issues;
    int size;

  public:
    IssueRepository();

    Issue** getIssues();

    Issue** getIssues(int& size, bool (*predicate)(Issue *));

    int getSize();

    void addIssue(Issue* issue);

    void removeIssue(Issue* issue);

    void removeIssue(int index);
};