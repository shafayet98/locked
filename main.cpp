#include <iostream>
#include <iostream>
#include <termios.h> // For terminal I/O functions
#include <unistd.h>  // For STDIN_FILENO
#include <string>
#include <map>
using namespace std;

int main(){

    cout << "Welcome to Locked!" << endl;
    cout << "Enter Option: " << endl;
    cout << "1. Register with Master Password" << endl;
    cout << "2. Add New Password" << endl;
    cout << "3. View Passwords" << endl;
    cout << "4. Delete Password" << endl;
    cout << "5. Exit" << endl;

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