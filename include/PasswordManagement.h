// PasswordManagement.h

#ifndef PASSWORDMANAGEMENT_H
#define PASSWORDMANAGEMENT_H

#include <string>

namespace PasswordManagement {
    void storeMasterPassword(const std::string& masterpass, const std::string& username);
}

#endif // PASSWORDMANAGEMENT_H