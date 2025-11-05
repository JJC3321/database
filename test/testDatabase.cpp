//------------- Test case for Database-------------// 

#include "../database.h"

int main() {
    Database db;
    
    // Add the existing data
    db.addInformation("Bobby", "Wu", 56, "bobbyW56@gmail.com");
    db.addInformation("Wiley", "Moore", 35, "wileyM35@gmail.com");
    db.addInformation("John", "Bauer", 65, "JohnB65@gmail.com");
    
    // Write in new table format
    std::cout << "Writing data in table format..." << std::endl;
    db.write();
    std::cout << "Done! Check data/data.frm to see the table format." << std::endl;
    
    // Test reading it back
    Database db2;
    std::cout << "\nReading data back from table format..." << std::endl;
    db2.read();
    
    // Display all to verify
    std::cout << "\nVerifying data was read correctly:" << std::endl;
    db2.displayAll();
    
    return 0;
}
