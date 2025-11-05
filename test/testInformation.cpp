//------------- Test case for infomation.h-------------// 

#include <iostream>
#include "information.h"

using std :: cout;
using std :: endl; 

int main(){
    
    cout << endl;
    cout << "Testing the information class." << endl << endl; 

    information information;

    information.setFirstName("Jian Jin");
    information.setLastName("Chen");
    information.setAge(22);
    information.setEmail("jianjinchen59@gmail.com");
    information.display();
    
}
