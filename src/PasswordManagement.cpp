// PasswordManagement.cpp
#include "PasswordManagement.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>
#include <fstream>

namespace PasswordManagement
{

    void storeMasterPassword(const std::string &masterpass, const std::string &username)
    {
        // Create a JSON object
        rapidjson::Document document;
        document.SetObject();

        // Add the master password to the JSON object
        rapidjson::Document::AllocatorType &allocator = document.GetAllocator();
        document.AddMember(rapidjson::StringRef("master_password"),
                           rapidjson::Value(masterpass.c_str(), allocator).Move(),
                           allocator);
        document.AddMember(rapidjson::StringRef("username"),
                           rapidjson::Value(username.c_str(), allocator).Move(),
                           allocator);


        // Convert JSON object to string
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        document.Accept(writer);

        std::ofstream file("/Users/shafayetulislam/locked/.data/credentials.json");
        if (file.is_open())
        {
            file << buffer.GetString();
            file.close();
            std::cout << "Credentials stored in JSON file successfully." << std::endl;
        }
        else
        {
            std::cerr << "Error opening JSON file for writing." << std::endl;
        }
    }

} // namespace PasswordManagement