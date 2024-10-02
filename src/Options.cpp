#include "/Users/shafayetulislam/Documents/locked/include/Options.h"
#include <iostream>
#include <string>
using namespace std;

Options::Options() : option1masterpass("Option 1: Enter Master Password:"), 
    option2addpass("Option 2: Add new password"),
    option3viewpass("Option 3: View Passwords"),
    option4deletepass("Option 4: Delete Passwords"),
    option5exitapplication("Option 5: Exit Application"){

}

void Options::displayOptions(){
    cout << option1masterpass << endl;
    cout << option2addpass << endl;
    cout << option3viewpass << endl;
    cout << option4deletepass << endl;
    cout << option5exitapplication << endl;
}   
