#pragma once

// An enum class is used here to scope the enumerator
// Otherwise the following error will occur "error: `none` conflicts with a previous declaration"
enum class IssueType {
    none,
    story,
    bug,
    epic
};