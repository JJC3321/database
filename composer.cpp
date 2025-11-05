//------------- Composer Implementation -------------// 
#include "composer.h"
#include <iostream>

using std::cout;
using std::endl;

// Constructor
Composer::Composer() {
    firstName_ = "";
    Lastname_ = "";
    age_ = 0;
    email_ = "";
    ranking_ = kDefaultRanking;
}

// Destructor
Composer::~Composer() {
    // Cleanup if needed
}

// Mutators
void Composer::setFirstName(string firstName) {
    firstName_ = firstName;
}

void Composer::setLastName(string lastName) {
    Lastname_ = lastName;
}

void Composer::setAge(int age) {
    age_ = age;
}

void Composer::setEmail(string email) {
    email_ = email;
}

void Composer::setRank(int rank) {
    ranking_ = rank;
}

// Accessors
string Composer::firstName() {
    return firstName_;
}

string Composer::LastName() {
    return Lastname_;
}

int Composer::age() {
    return age_;
}

string Composer::email() {
    return email_;
}

int Composer::rank() {
    return ranking_;
}

// Methods
void Composer::promote(int increment) {
    ranking_ += increment;
}

void Composer::demote(int decrement) {
    ranking_ -= decrement;
}

void Composer::display() {
    cout << "Composer Information:" << endl;
    cout << "Name: " << firstName_ << " " << Lastname_ << endl;
    cout << "Age: " << age_ << endl;
    cout << "Email: " << email_ << endl;
    cout << "Ranking: " << ranking_ << endl;
}