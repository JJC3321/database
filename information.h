//-------------Infomation for Database -------------// 
#include <string>

using std :: string;

class information{
    public:

        // Constructor & Deconstructor 

        information(); 
        ~information(); 
        
        // Accessors and  Mutators 
    
        void setFirstName(string firstName);
        string firstName();
        void setLastName(string lastName);
        string LastName(); 
        void setAge(int age);
        int age();
        void setEmail(string email);
        string email();
        void setId(int id);
        int id(); 

        // Methods

        void display();


    private:
        string firstName_;
        string Lastname_;
        int age_;
        string email_; 
        int id_; 
};
