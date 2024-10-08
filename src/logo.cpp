#include "Logo.h"
#include <iostream>

namespace Logo
{

    TerminalLogo::TerminalLogo()
    {
        // Initialize the logo
        logo = {
            " __          __  _                            _______      _                _            _ ",
            " \\ \\        / / | |                          |__   __|    | |              | |          | |",
            "  \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___     | | ___   | |     ___   ___| | _____  __| |",
            "   \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\    | |/ _ \\  | |    / _ \\ / __| |/ / _ \\/ _` |",
            "    \\  /\\  /  __/ | (_| (_) | | | | | |  __/    | | (_) | | |___| (_) | (__|   <  __/ (_| |",
            "     \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|    |_|\\___/  |______\\___/ \\___|_|\\_\\___|\\__,_|"};
    };

    void TerminalLogo::display() const
    {
        for (const auto &line : logo)
        {
            std::cout << line << std::endl;
        };
    }
}