#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <string>
using namespace std;

class Options{

public:
    Options();
    void displayOptions();

private:
    string option1masterpass;
    string option2addpass;
    string option3viewpass;
    string option4deletepass;
    string option5exitapplication;
};

#endif