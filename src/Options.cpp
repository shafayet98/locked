#include "Options.h"
#include <iostream>
#include <fstream>


Options::Options::Options() 
    : option1masterpass("Option 1: Enter Master Password:")
    , option2addpass("Option 2: Add new password")
    , option3viewpass("Option 3: View Passwords")
    , option4deletepass("Option 4: Delete Passwords")
    , option5exitapplication("Option 5: Exit Application")
{
}

void Options::Options::displayOptions()
{

    // Check if credentials file exists 
    std::string filePath = "/Users/shafayetulislam/Documents/Locked/.data/masters.json";
    std::ifstream file(filePath);
    bool masterPasswordExists = false;
    
    // checking if the file has content
    if (file.good()) {
        std::string content;
        std::getline(file, content);
        masterPasswordExists = !content.empty();
    }
    file.close();

    if (!masterPasswordExists) {
        std::cout << option1masterpass << std::endl;
    }
    
    std::cout << option2addpass << std::endl;
    std::cout << option3viewpass << std::endl;
    std::cout << option4deletepass << std::endl;
    std::cout << option5exitapplication << std::endl;
}