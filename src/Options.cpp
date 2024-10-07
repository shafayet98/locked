#include "Options.h"
#include <iostream>

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
    std::cout << option1masterpass << std::endl;
    std::cout << option2addpass << std::endl;
    std::cout << option3viewpass << std::endl;
    std::cout << option4deletepass << std::endl;
    std::cout << option5exitapplication << std::endl;
}