#include "data/issue-type.h"
#include "helpers/issue-creator.h"

#include <iostream>

int main() {
    IssueCreator creator;
    Issue issue = creator.createIssue();

    issue.print();

    return 0;
}