//------------- Database -------------// 

#include <iostream>
#include "information.h"
#include <fstream>
#include <vector>

using std :: string;

class Database{
    
    public: 

        // Constructor & Deconstructor 

        Database();
        ~Database(); 
        
        //Method
        
        information& addInformation(string firstName, string lastName, int age,  string email);
        information& getinformation(string lastName);
        void displayAll(); 
        void write();
        void read(); 

        
    private:
        std::vector<information> information_;
        int nextSlot; 
};