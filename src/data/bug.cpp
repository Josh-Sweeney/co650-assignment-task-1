#include "bug.h"

// 2. Encapsulation - The Bug constructor is public so it can be called
// from outside the class utilizing the private Issue constructor.
// 8. Constructors - The Bug constructor is used to initialize the title,
// description and status properties. The type property is set to
// IssueType::bug because this is a Bug class.
Bug::Bug(std::string title, std::string description, IssueStatus status) : Issue(title, description, status, IssueType::bug) {}

// 2. Encapsulation - The print method is public so it can be called
// from outside the class.
// 4. Polymorphic Behaviour - The print method is overridden so it
// behaviour is different to the Issue class. In this case, the print
// method prints the bug, using a blue icon, to the console.
// 6. Friendship - The private statusToString method is a friend function of
// the Issue class so that it can be accessed within the Bug class despite
// being private.
// 7. Static Methods - The statusToString method is called from the
// print method. The statusToString method is static so it can be
// called without an instance of the Bug class.
void Bug::print() {
    std::cout << "[" << statusToString(this->status) << "]" << " 📘 " << this->title << " - " << this->description << std::endl;
}