//------------- Database -------------// 

#include <iostream>
#include "composer.h"

using std :: string;

const int kMaxComposers = 100; 


class Database{
    
    public: 

        // Constructor & Deconstructor 

        Database();
        ~Database(); 
        
        //Method
        
        Composer& AddComposer(string firstName, string lastName, int age,  string email);
        Composer& getComposer(string lastName);
        void displayAll(); 
    
    
    private:
        Composer composer_[kMaxComposers];
        int nextSlot; 
};