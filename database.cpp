//------------- Database Implementation-------------// 

#include "database.h"

Database :: Database(){
    nextSlot = 0;
}


Database :: ~Database(){

}


void Database :: write(){
   
    std :: ofstream outPutFile; 
    outPutFile.open("../data/data.frm");
    
    
    if(!outPutFile.is_open()) { 
        std :: cout << "error file not open" << std :: endl;
        return;
    }

    outPutFile << nextSlot << std :: endl;

    // Write infomation to database 
    for(int i = 0; i < nextSlot; i++){
        outPutFile << information_[i].id() << std :: endl;
        outPutFile << information_[i].firstName() << std :: endl;
        outPutFile << information_[i].LastName() << std :: endl;
        outPutFile << information_[i].age() << std :: endl;
        outPutFile << information_[i].email() << std :: endl;
    }

    outPutFile.close(); 
}



information& Database :: addInformation(string firstName, string lastName, int age, string email){
    
    information newinformation;
    newinformation.setId(nextSlot + 1);  // Auto-assign ID starting from 1
    newinformation.setFirstName(firstName);
    newinformation.setLastName(lastName);
    newinformation.setAge(age);
    newinformation.setEmail(email);
    
    information_.push_back(newinformation);
    nextSlot++;
    return information_[nextSlot - 1];
}


information& Database :: getinformation(string lastName){
    for(int i = 0; i < nextSlot; i++){
        if(information_[i].LastName() == lastName){
            return information_[i];
        }
    }
    
    // information not found - return a static empty information
    std :: cout << "last name '" << lastName << "' not found!" << std :: endl;
    static information emptyinformation;
    return emptyinformation;
}

void Database :: displayAll(){
    if(nextSlot == 0){
        std :: cout << "Database is empty!" << std :: endl;
        return;
    }
    
    std :: cout << "=== Database Contents ===" << std :: endl;
    std :: cout << "Total elements: " << nextSlot << std :: endl << std :: endl;
    
    for(int i = 0; i < nextSlot; i++){
        std :: cout << "Name #" << (i + 1) << ":" << std :: endl;
        information_[i].display();
        std :: cout << std :: endl;
    }
}