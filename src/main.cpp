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
                    cout << "Please Enter Website Name (mandatory & must be unique): " << "\n";
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
                string requested_password;
                string website_name;

                cout << "Please Enter Your Master Password: ";
                cin >> mpass;
                // check master password 
                bool pass_match = PasswordManagement::checkMasterPassword(mpass);
                // get the key
                if (pass_match == true){
                    // ask for the website name
                    cout << "Please Enter the website name for the requested password: ";
                    cin >> website_name;
                    requested_password =  PasswordManagement::showRequestedPassword(website_name);
                    // show the password 
                    cout << "Requested Password: " << requested_password << "\n";
                    // let the user copy the password :: Implement Later
                }else{
                    cout << "Wrong Master Password. Please Try Again." << "\n";
                }
                

            }

            else if (selectedOption == 4){
                
                string website_name_del;
                string mpass;

                // get the website name for the password that needs to be deleted
                cout << "Please Enter the website name of the password you want to delete: ";
                cin >> website_name_del;
                // get the master password and verify it
                cout << "Please enter the master passwrod for verification: ";
                cin >> mpass;
                // check master password 
                bool pass_match = PasswordManagement::checkMasterPassword(mpass);
                if (pass_match == true){
                    // implement deletePassword(website_name_del)
                    bool isDeleted = PasswordManagement::deletePassword(website_name_del);
                    if (isDeleted == true){
                        cout << "Password has been deleted Successfully" << "\n";
                    }else{
                        cout << "Error has been occured during deleting password" << "\n";
                    }
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