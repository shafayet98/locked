#include "/Users/shafayetulislam/Documents/locked/include/Options.h"
#include "/Users/shafayetulislam/Documents/locked/include/PasswordManagement.h"


#include <iostream>
#include <termios.h> // For terminal I/O functions
#include <unistd.h>  // For STDIN_FILENO
#include <fstream>
#include <string>
#include <map>



using namespace std;

int main(){

    Options options;

    cout << "Welcome to Locked!" << endl;
    options.displayOptions();


    int selectedOption;
    string masterPassword;

    bool exitApplication = false;
    while(!exitApplication){
        cout << "select option: ";
        cin >> selectedOption;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid Input. Input must be a number." << endl;
        }else{
            if (selectedOption == 1){
                cout << "Enter Master Password: ";
                cin >> masterPassword;
                cout << "You're master password is: " << masterPassword << endl;

                PasswordManagement::storeMasterPassword(masterPassword);
            }
            if (selectedOption == 5){
                cout << "Exiting." <<endl;
                exitApplication = true;
                break;
            }
        }
    }

    return 0;
}