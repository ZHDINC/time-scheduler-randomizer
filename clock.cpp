#include"clock.h"

Clock::Clock(std::string strToParse)
{
    std::vector<std::string> time = ParserUtilities::LineItemParser(strToParse, ':');
    hours = stoi(time[0]);
    minutes = stoi(time[1]);
}

void Clock::AddMinutes(int minutesToAdd)
{
    minutes += minutesToAdd;
    if(minutes >= 60)
    {
        minutes -= 60;
        hours++;
    }
}

bool Clock::operator==(Clock& rhs)
{
    if((this->GetHours() == rhs.GetHours()) && (this->GetMinutes() == rhs.GetMinutes()))
    {
        return true;
    }
    return false;
}

bool Clock::operator!=(Clock& rhs)
{
    if((this->GetHours() != rhs.GetHours()) || (this->GetMinutes() != rhs.GetMinutes()))
    {
        return true;
    }
    return false;
}

bool Clock::operator>(Clock& rhs)
{
    if(this->GetHours() > rhs.GetHours())
    {
        return true;
    }
    if((this->GetHours() == rhs.GetHours()) && (this->GetMinutes() > rhs.GetMinutes()))
    {
        return true;
    }
    return false;
}

bool Clock::operator<(Clock& rhs)
{
    if(this->GetHours() < rhs.GetHours())
    {
        return true;
    }
    if((this->GetHours() == rhs.GetHours()) && (this->GetMinutes() < rhs.GetMinutes()))
    {
        return true;
    }
    return false;
}