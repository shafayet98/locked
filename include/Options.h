#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

namespace Options
{
    class Options
    {
    public:
        Options();
        void displayOptions();
    private:
        std::string option1masterpass;
        std::string option2addpass;
        std::string option3viewpass;
        std::string option4deletepass;
        std::string option5exitapplication;
    };
}

#endif