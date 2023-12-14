#include "story.h"

// 2. Encapsulation - The Story constructor is public so it can be called
// from outside the class utilizing the private Issue constructor.
// 8. Constructors - The Story constructor is used to initialize the
// title, description and status properties. The type property is set
// to IssueType::story because this is a Story class.
Story::Story(std::string title, std::string description, IssueStatus status) : Issue(title, description, status, IssueType::story) {}

// 2. Encapsulation - The print method is public so it can be called
// from outside the class.
// 4. Polymorphic Behaviour - The print method is overridden so its
// behaviour is different to the Issue class. In this case, the print
// method prints the story, using a green icon, to the console.
// 6. Friendship - The private statusToString method is a friend function of
// the Issue class so that it can be accessed within the Story class despite
// being private.
// 7. Static Methods - The statusToString method is called from the
// print method. The statusToString method is static so it can be
// called without an instance of the Story class.
void Story::print() {
    std::cout << "[" << statusToString(this->status) << "]" << " 📗 " << this->title << " - " << this->description << std::endl;
}