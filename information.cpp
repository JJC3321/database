//------------- Infomation Implementation -------------// 
#include "information.h"
#include <iostream>

using std::cout;
using std::endl;

// Constructor
information::information() {
    firstName_ = "";
    Lastname_ = "";
    age_ = 0;
    email_ = "";
    id_ = 0;
}

// Destructor
information::~information() {
    // Cleanup if needed
}

// Mutators
void information::setFirstName(string firstName) {
    firstName_ = firstName;
}

void information::setLastName(string lastName) {
    Lastname_ = lastName;
}

void information::setAge(int age) {
    age_ = age;
}

void information::setEmail(string email) {
    email_ = email;
}

void information::setId(int id) {
    id_ = id;
}

// Accessors
string information::firstName() {
    return firstName_;
}

string information::LastName() {
    return Lastname_;
}

int information::age() {
    return age_;
}

string information::email() {
    return email_;
}

int information::id() {
    return id_;
}

// Methods

void information::display() {
    cout << "information Information:" << endl;
    cout << "ID: " << id_ << endl;
    cout << "Name: " << firstName_ << " " << Lastname_ << endl;
    cout << "Age: " << age_ << endl;
    cout << "Email: " << email_ << endl;
}
