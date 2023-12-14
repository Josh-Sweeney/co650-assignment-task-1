#pragma once

// 1. Abstraction - The IssueType enum stores the different issue
// types so that classes, that deal with Issues, do not need to
// handle the raw type values.
// ! NOTE: An enum class is used here to scope the enumerator
// ! Otherwise the following error will occur "error: `none` conflicts with a previous declaration"
enum class IssueType {
    none,
    story,
    bug,
    epic
};