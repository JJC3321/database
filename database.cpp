//------------- Database Implementation-------------// 

#include "database.h"
#include <iomanip>
#include <sstream>

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

    // Write header with fixed-width columns
    outPutFile << std::left 
               << std::setw(5) << "ID"
               << std::setw(13) << "FirstName"
               << std::setw(13) << "LastName"
               << std::setw(5) << "Age"
               << std::setw(25) << "Email"
               << std :: endl;

    // Write information with fixed-width columns
    for(int i = 0; i < nextSlot; i++){
        outPutFile << std::left
                   << std::setw(5) << information_[i].id()
                   << std::setw(13) << information_[i].firstName()
                   << std::setw(13) << information_[i].LastName()
                   << std::setw(5) << information_[i].age()
                   << std::setw(25) << information_[i].email()
                   << std :: endl;
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

void Database :: read(){
    std :: ifstream inputFile;
    inputFile.open("../data/data.frm");
    
    if(!inputFile.is_open()) {
        std :: cout << "Error: Could not open file for reading" << std :: endl;
        return;
    }
    
    // Clear existing data
    information_.clear();
    nextSlot = 0;
    
    std :: string line;
    
    // Skip header line
    std::getline(inputFile, line);
    
    // Read each data line
    while(std::getline(inputFile, line)) {
        if(line.empty()) continue;  // Skip empty lines
        
        // Parse fixed-width columns
        int id, age;
        std :: string firstName, lastName, email;
        
        // Extract data using substring positions
        // ID: columns 0-4 (5 chars)
        // FirstName: columns 5-17 (13 chars)
        // LastName: columns 18-30 (13 chars)
        // Age: columns 31-35 (5 chars)
        // Email: columns 36-60 (25 chars)
        
        std::stringstream ss;
        
        // Parse ID
        ss.str(line.substr(0, 5));
        ss >> id;
        ss.clear();
        
        // Parse FirstName (trim trailing spaces)
        firstName = line.substr(5, 13);
        firstName.erase(firstName.find_last_not_of(" \t\n\r\f\v") + 1);
        
        // Parse LastName (trim trailing spaces)
        lastName = line.substr(18, 13);
        lastName.erase(lastName.find_last_not_of(" \t\n\r\f\v") + 1);
        
        // Parse Age
        ss.str(line.substr(31, 5));
        ss >> age;
        ss.clear();
        
        // Parse Email (trim trailing spaces)
        if(line.length() > 36) {
            email = line.substr(36);
            email.erase(email.find_last_not_of(" \t\n\r\f\v") + 1);
        }
        
        // Add to database
        information newInfo;
        newInfo.setId(id);
        newInfo.setFirstName(firstName);
        newInfo.setLastName(lastName);
        newInfo.setAge(age);
        newInfo.setEmail(email);
        
        information_.push_back(newInfo);
        nextSlot++;
    }
    
    inputFile.close();
    std :: cout << "Loaded " << nextSlot << " records from database." << std :: endl;
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