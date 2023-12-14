#pragma once

// 1. Abstraction - The IssueStatus enum stores the different issue
// statuses so that classes, that deal with Issues, do not need to
// handle the raw status values.
// ! NOTE: An enum class is used here to scope the enumerator
// ! Otherwise the following error will occur "error: `none` conflicts with a previous declaration"
enum class IssueStatus {
    none,
    requirements,
    backlog,
    inDevelopment,
    developed,
    uat,
    released
};