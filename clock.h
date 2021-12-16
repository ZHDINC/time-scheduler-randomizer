#include<string>
#include<vector>
#include<iostream>
#include"parserutilities.h"

class Clock
{
    int hours;
    int minutes;
    bool nextDay;
public:
    Clock(int hours, int minutes, bool nextDay) : hours{hours}, minutes{minutes}, nextDay{nextDay} { }
    Clock(std::string strToParse);
    ~Clock() { };
    void AddMinutes(int minutesToAdd);
    int GetHours() const { return hours; }
    int GetMinutes() const { return minutes; }
    bool GetNextDay() const { return nextDay; }

    bool operator==(Clock& rhs);
    bool operator!=(Clock& rhs);
    bool operator>(Clock& rhs);
    bool operator<(Clock& rhs);
};