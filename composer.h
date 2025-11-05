//-------------Composer for Database -------------// 
#include <string>

using std :: string;

const int kDefaultRanking = 10; 

class Composer{
    public:

        // Constructor & Deconstructor 

        Composer(); 
        ~Composer(); 
        
        // Accessors and  Mutators 
    
        void setFirstName(string firstName);
        string firstName();
        void setLastName(string lastName);
        string LastName(); 
        void setAge(int age);
        int age();
        void setEmail(string email);
        string email();
        void setRank(int rank);
        int rank(); 

        // Methods

        void promote(int increment);
        void demote(int decrement);
        void display();


    private:
        string firstName_;
        string Lastname_;
        int age_;
        string email_; 
        int ranking_; 
};