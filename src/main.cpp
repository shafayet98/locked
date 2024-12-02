#include "Options.h"
#include "PasswordManagement.h"
#include "Logo.h"


#include <iostream>
#include <termios.h> // For terminal I/O functions
#include <unistd.h>  // For STDIN_FILENO
#include <fstream>
#include <string>
#include <map>



using namespace std;



int main(){

    
    Options::Options menu;

    Logo::TerminalLogo terminal_logo;
    terminal_logo.display();
    cout << endl;
    cout << "A password management system for terminal!!!" << endl;
    cout << endl;
    menu.displayOptions();


    int selectedOption;
    string masterPassword;
    string tag;
    string website;
    string username;

    PasswordManagement::storeMasterPassword("your_master_password", "your_username");

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
                cout << "Enter username: ";
                cin >> username;

                // cout << "You're master password is: " << masterPassword << endl;

                PasswordManagement::storeMasterPassword(masterPassword, username);
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