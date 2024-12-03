// PasswordManagement.cpp
#include "PasswordManagement.h"

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>
#include <fstream>
#include <sstream>

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

    bool checkMasterPassword(const string mpass){
        // Read the file content
        std::ifstream file("/Users/shafayetulislam/Documents/Locked/.data/masters.json");
        if (!file.is_open()) {
            // Handle error
            cout << "File Not Found" << "\n";
            return false;
        }

        // Read file into string
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string content = buffer.str();

        // Parse JSON
        rapidjson::Document document;
        document.Parse(content.c_str());

        if (document.HasParseError()) {
            // Handle parsing error
            cout << "Parse Error" << "\n";
            return false;
        } 

        if (document.HasMember("master_password") && document["master_password"].IsString()) {
            string master_pass_found = document["master_password"].GetString();
            if (mpass == master_pass_found){
                return true;
            }
        }
        return false;
        
    }

    void saveNewPassword(const string new_added_pass, const string new_pass_email, const string new_pass_website){

        // specify file paths
        std::string dirPath = "/Users/shafayetulislam/Documents/Locked/.data";
        std::string filePath = dirPath + "/credentials.json";


        // read the existing json
        rapidjson::Document document;

        std::ifstream inFile(filePath);
        if (inFile.is_open()) {
            std::stringstream buffer;
            buffer << inFile.rdbuf();
            std::string content = buffer.str();
            inFile.close();
            
            // Parse existing content
            if (!content.empty()) {
                document.Parse(content.c_str());
            }
        }

        if (!document.IsArray()) {
            document.SetArray();
        }

        // Create new password object
        rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
        rapidjson::Value newEntry(rapidjson::kObjectType);
        
        newEntry.AddMember("password", 
            rapidjson::Value(new_added_pass.c_str(), allocator).Move(),
            allocator);
        newEntry.AddMember("email",
            rapidjson::Value(new_pass_email.c_str(), allocator).Move(),
            allocator);
        newEntry.AddMember("website",
            rapidjson::Value(new_pass_website.c_str(), allocator).Move(),
            allocator);
        
        // Add the new entry to the array
        document.PushBack(newEntry, allocator);
        
        // Write back to file
        std::ofstream outFile(filePath);
        if (!outFile) {
            std::cerr << "Error opening file for writing." << std::endl;
            return;
        }
        
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        document.Accept(writer);
        outFile << buffer.GetString() << std::endl;
        outFile.close();

    }


} // namespace PasswordManagement