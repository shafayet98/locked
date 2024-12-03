// PasswordManagement.h

#ifndef PASSWORDMANAGEMENT_H
#define PASSWORDMANAGEMENT_H


#include <string>
using namespace std;


namespace PasswordManagement {
    void storeMasterPassword(const string masterpass, const string username);
    bool checkMasterPassword(const string mpass);
    void saveNewPassword(const string new_added_pass, const string new_pass_email, const string new_pass_website);
    string showRequestedPassword(const string website_name);
    bool deletePassword(const string website_name_del);
}

#endif // PASSWORDMANAGEMENT_H