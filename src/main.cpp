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

            else if (selectedOption == 2){
                string mpass;
                string new_added_pass;
                string new_pass_email;
                string new_pass_website;

                // ask for master password
                cout << "Please Enter Your Master Password: ";
                cin >> mpass;
                bool pass_match = PasswordManagement::checkMasterPassword(mpass);
                // check if the master password is correct
                // ask for the new password
                // ask for corresponding website
                // ask for corresponding email
                if (pass_match == true){
                    cout << "Please Enter Your New Password: " << "\n";
                    cin >> new_added_pass;
                    cout << "Please Enter Your Email (mandatory): " << "\n";
                    cin >> new_pass_email;
                    cout << "Please Enter Website Name (mandatory): " << "\n";
                    cin >> new_pass_website;

                    PasswordManagement::saveNewPassword(new_added_pass, new_pass_email, new_pass_website);

                }else{
                    cout << "Wrong Master Password. Please Try Again." << "\n";
                }
                
                // save the password
            }

            else if (selectedOption == 3){
                // get master password 
                string mpass;
                cout << "Please Enter Your Master Password: ";
                cin >> mpass;
                // check master password 
                bool pass_match = PasswordManagement::checkMasterPassword(mpass);
                // get the key
                if (pass_match == true){
                    // show the password 
                    // let the user copy the password 
                }else{
                    cout << "Wrong Master Password. Please Try Again." << "\n";
                }
                

            }




            else if (selectedOption == 5){
                cout << "Exiting." <<endl;
                exitApplication = true;
                break;
            }

            else{
                cout << "Please select available options" << "\n";
            }
        }
    }
    return 0;
}