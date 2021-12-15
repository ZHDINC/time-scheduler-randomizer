#include<string>
#include<vector>
#include"parserutilities.h"

class Clock
{
    int hours;
    int minutes;
    bool nextDay = false;
public:
    Clock(int hours, int minutes) : hours{hours}, minutes{minutes} { }
    Clock(std::string strToParse);
    ~Clock() { };
    void AddMinutes(int minutesToAdd);
    int GetHours() const { return hours; }
    int GetMinutes() const { return minutes; }

    bool operator==(Clock& rhs);
    bool operator!=(Clock& rhs);
    bool operator>(Clock& rhs);
    bool operator<(Clock& rhs);
};