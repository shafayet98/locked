// PasswordManagement.cpp
#include "PasswordManagement.h"

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>
#include <fstream>

using namespace std;

namespace PasswordManagement
{

    void storeMasterPassword(const string masterpass, const string username)
    {

        std::string dirPath = "/Users/shafayetulislam/Documents/Locked/.data";
        std::string filePath = dirPath + "/masters.json";

        std::ofstream file(filePath, std::ios::out);
        if (!file)
        {
            std::cerr << "Error opening file for writing." << std::endl;
            return;
        }

        rapidjson::Document document;
        document.SetObject();
        
        rapidjson::Document::AllocatorType &allocator = document.GetAllocator();
        document.AddMember(rapidjson::StringRef("master_password"),
            rapidjson::Value(masterpass.c_str(), allocator).Move(),
            allocator);
        document.AddMember(rapidjson::StringRef("username"),
            rapidjson::Value(username.c_str(), allocator).Move(),
            allocator);

        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        document.Accept(writer);

        file << buffer.GetString() << std::endl;
        file.close();
    }

} // namespace PasswordManagement