// PasswordManagement.cpp
#include "PasswordManagement.h"

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem> 

using namespace std;

namespace PasswordManagement
{
    const string BASE_DIR = "./.data";

    void storeMasterPassword(const string masterpass, const string username)
    {

        // Ensure .data directory exists
        std::filesystem::create_directory(BASE_DIR);

        std::string dirPath = BASE_DIR;
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

        cout << "Master Password has been created Successfully" << "\n";
    }

    bool checkMasterPassword(const string mpass)
    {
        string filePath = BASE_DIR + "/masters.json";
        // Read the file content
        std::ifstream file(filePath);
        if (!file.is_open())
        {
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

        if (document.HasParseError())
        {
            // Handle parsing error
            cout << "Parse Error" << "\n";
            return false;
        }

        if (document.HasMember("master_password") && document["master_password"].IsString())
        {
            string master_pass_found = document["master_password"].GetString();
            if (mpass == master_pass_found)
            {
                return true;
            }
        }
        return false;
    }

    void saveNewPassword(const string new_added_pass, const string new_pass_email, const string new_pass_website)
    {

        // specify file paths
        std::string dirPath = BASE_DIR;
        std::string filePath = dirPath + "/credentials.json";

        // read the existing json
        rapidjson::Document document;

        std::ifstream inFile(filePath);
        if (inFile.is_open())
        {
            std::stringstream buffer;
            buffer << inFile.rdbuf();
            std::string content = buffer.str();
            inFile.close();

            // Parse existing content
            if (!content.empty())
            {
                document.Parse(content.c_str());
            }
        }

        if (!document.IsArray())
        {
            document.SetArray();
        }

        // Create new password object
        rapidjson::Document::AllocatorType &allocator = document.GetAllocator();
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
        if (!outFile)
        {
            std::cerr << "Error opening file for writing." << std::endl;
            return;
        }

        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        document.Accept(writer);
        outFile << buffer.GetString() << std::endl;
        outFile.close();

        cout << "Password has been saved Successfully" << "\n";
    }

    string showRequestedPassword(const string website_name)
    {
        std::string dirPath = BASE_DIR;
        std::string filePath = dirPath + "/credentials.json";

        // Read the file
        std::ifstream file(filePath);
        if (!file.is_open())
        {
            std::cerr << "Error: Could not open credentials file." << std::endl;
            return "";
        }

        // Read file into string
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string content = buffer.str();
        file.close();

        rapidjson::Document document;
        document.Parse(content.c_str());

        if (document.HasParseError())
        {
            std::cerr << "Error: Could not parse credentials file." << std::endl;
            return "";
        }

        // Ensure document is an array
        if (!document.IsArray())
        {
            std::cerr << "Error: Invalid credentials file format." << std::endl;
            return "";
        }

        // Search through the array for matching website
        for (const auto &entry : document.GetArray())
        {
            if (entry.HasMember("website") &&
                entry["website"].IsString() &&
                std::string(entry["website"].GetString()) == website_name)
            {

                // Found matching website, return the password
                if (entry.HasMember("password") && entry["password"].IsString())
                {
                    return entry["password"].GetString();
                }
            }
        }

        // If no matching website found
        return "No password found for this website.";
    }

    bool deletePassword(const string website_name_del)
    {

        string dirPath = BASE_DIR;
        string filePath = dirPath + "/credentials.json";

        // get access of the file
        ifstream file(filePath);
        if (!file.is_open())
        {
            cout << "Error: Could not open the credential file" << "\n";
            return false;
        }

        // read the content of the file
        stringstream buffer;
        buffer << file.rdbuf();
        string content = buffer.str();
        file.close();

        rapidjson::Document document;
        document.Parse(content.c_str());

        if (document.HasParseError() || !document.IsArray())
        {
            cout << "Error: Parsing error occured while converting to JSON" << "\n";
            return false;
        }

        bool foundWebsite = false;
        for (rapidjson::SizeType i = 0; i < document.Size(); i++)
        {
            if (document[i].HasMember("website") && document[i]["website"].IsString() && string(document[i]["website"].GetString()) == website_name_del)
            {
                // remove the item
                document.Erase(document.Begin() + i);
                foundWebsite = true;
                break;
            }
        }

        if (!foundWebsite)
        {
            cout << "Website not found." << "\n";
            return false;
        }

        // write the updated array after removing back to your file
        ofstream outFile(filePath);
        if (!outFile)
        {
            cout << "Error opening file for writing." << "\n";
            return false;
        }

        rapidjson::StringBuffer bfr;
        rapidjson::Writer<rapidjson::StringBuffer> writer(bfr);
        document.Accept(writer);
        outFile << bfr.GetString() << endl;
        outFile.close();

        return true;
    }

} // namespace PasswordManagement