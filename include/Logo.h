#ifndef LOGO_H
#define LOGO_H

#include <string>
#include <vector>

namespace Logo {

class TerminalLogo {
private:
    std::vector<std::string> logo;

public:
    TerminalLogo();
    void display() const;
};

} // namespace Logo

#endif // LOGO_H