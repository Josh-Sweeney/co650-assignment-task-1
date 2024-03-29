#pragma once

#include "../data/issue.h"
#include "../data/bug.h"
#include "../data/epic.h"
#include "../data/story.h"

// 1. Abstraction - The IssueRepository class exists to abstract the
// retrieval and manipulation of issues away from the user. In this
// case, issues are stored within a private array and can only be
// accessed or manipulated through this class.
class IssueRepository {
  private:
    // 2. Encapsulation - The issues array is private and can only be accessed
    // through the getIssues method.
    // 9. Pointers - The issues array is a pointer to an array of Issue pointers.
    Issue** issues;

    // 2. Encapsulation - The size property is private and can only be accessed
    // through the getSize method.
    int size;

  public:
    // 8. Constructors - The IssueRepository constructor is used to initialize the
    // issues array with some dummy data.
    IssueRepository();

    // 1. Abstraction - The getIssue method abstracts away the code required
    // to get an issue from the issues array.
    // 2. Encapsulation - The issues array is private and can only be accessed
    // through either the getIssue or getIssues methods.
    // 9. Pointers - The return type of the getIssue method is a pointer to an
    // Issue object.
    Issue* getIssue(int index);

    // 1. Abstraction - The getIssues method abstracts away the code required
    // to filter the issues array.
    // 5. Overloading - The getIssues method is overloaded so that it can be
    // called with or without a predicate.
    // 2. Encapsulation - The issues array is private and can only be accessed
    // through the getIssues method.
    Issue** getIssues();

    // 1. Abstraction - The getIssues method abstracts away the code required
    // to filter the issues array.
    // 2. Encapsulation - The issues array is private and can only be accessed
    // through the getIssues method.
    // 5. Overloading - The getIssues method is overloaded so that it can be
    // called with or without a predicate.
    // 9. Pointers - The size parameter is a pointer so that the filtered size
    // can be returned through the parameter. The filtered size must be returned
    // here since we can't modify the size of the repository as we are not
    // manipulating data.
    // 10. Functional Pointers - A functional pointer is used here so that the
    // issues can be filtered by a predicate. The predicate is a function is
    // ran for each item in the issues array and returns true or false . If the
    // predicate returns true, the issue is added to the result array.
    Issue** getIssues(int& filteredSize, bool (*predicate)(Issue *));

    // 2. Encapsulation - The size property is private and can only be accessed
    // through the getSize method.
    int getSize();

    // 1. Abstraction - The addIssue method abstracts away the code required
    // to add an issue to the issues array.
    // 2. Encapsulation - The issues array is private and can only be accessed
    // through the addIssue method.
    // 9. Pointers - The issue parameter is a pointer to an Issue object.
    void addIssue(Issue* issue);

    // 1. Abstraction - The removeIssue method abstracts away the code required
    // to remove an issue from the issues array.
    // 2. Encapsulation - The issues array is private and can only be accessed
    // through the removeIssue method.
    // 5. Overloading - The removeIssue method is overloaded so that it can be
    // called with or without an index.
    void removeIssue(int index);

    // 1. Abstraction - The removeIssue method abstracts away the code required
    // to remove an issue from the issues array.
    // 2. Encapsulation - The issues array is private and can only be accessed
    // through the removeIssue method.
    // 5. Overloading - The removeIssue method is overloaded so that it can be
    // called with or without an index.
    // 9. Pointers - The issue parameter is a pointer to an Issue object.
    void removeIssue(Issue* issue);

    // 1. Abstraction - The removeIssues method abstracts away the code required
    // to remove issues from the issues array based on a predicate.
    // 2. Encapsulation - The issues array is private and can only be accessed
    // through the removeIssues method.
    // 10. Functional Pointers - A functional pointer is used here so that the
    // issues can be filtered by a predicate. The predicate is a function is
    // ran for each item in the issues array and returns true or false . If the
    // predicate returns true, the issue is removed from the issues array.
    // NOTE: Unlike getIssues(int& filteredSize, bool (*predicate)(Issue *)),
    // the size of the repository can be modified here since we are manipulating
    // data.
    void removeIssues(bool (*predicate)(Issue *));
};