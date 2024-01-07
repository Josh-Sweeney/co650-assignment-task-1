cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(Project)

add_executable(
    Project
    src/main.cpp
    src/data/bug.cpp
    src/data/bug.h
    src/data/epic.cpp
    src/data/epic.h
    src/data/issue-status.h
    src/data/issue-type.h
    src/data/issue.cpp
    src/data/issue.h
    src/data/story.cpp
    src/data/story.h
    src/domain/issue-repository.h
    src/domain/issue-repository.cpp
    src/helpers/issue-creator.cpp
    src/helpers/issue-creator.h
    src/helpers/issue-lister.h
    src/helpers/issue-lister.cpp
    src/helpers/issue-remover.h
    src/helpers/issue-remover.cpp
)