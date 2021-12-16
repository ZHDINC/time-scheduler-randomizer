#include"clock.h"

Clock::Clock(std::string strToParse)
{
    std::vector<std::string> time = ParserUtilities::LineItemParser(strToParse, ':', true);
    nextDay = false;
    hours = stoi(time[0]);
    minutes = stoi(time[1]);
    if(time.size() == 3)
    {
        if(hours == 12 && time[2] == "AM")
        {
            hours -= 12;
        }
        if(time[2] == "AM" && hours < 5)
        {
            nextDay = true;
        }
        if(time[2] == "PM" && hours != 12)
        {
            hours += 12;
        }
    }
}

void Clock::AddMinutes(int minutesToAdd)
{
    minutes += minutesToAdd;
    if((minutes >= 60) && (hours < 23))
    {
        minutes -= 60;
        hours++;
    }
    else if((minutes >= 60) && (hours >= 23))
    {
        minutes -= 60;
        hours -= 23;
        nextDay = true;
    }
}

bool Clock::operator==(Clock& rhs)
{
    if((this->GetHours() == rhs.GetHours()) && (this->GetMinutes() == rhs.GetMinutes()) && (this->GetNextDay() == rhs.GetNextDay()))
    {
        return true;
    }
    return false;
}

bool Clock::operator!=(Clock& rhs)
{
    if((this->GetHours() != rhs.GetHours()) || (this->GetMinutes() != rhs.GetMinutes()) || (this->GetNextDay() != rhs.GetNextDay()))
    {
        return true;
    }
    return false;
}

bool Clock::operator>(Clock& rhs)
{
    if(this->GetNextDay() > rhs.GetNextDay())
    {
        return true;
    }
    if((this->GetNextDay() == rhs.GetNextDay()) && (this->GetHours() > rhs.GetHours()))
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
    if(this->GetNextDay() < rhs.GetNextDay())
    {
        return true;
    }
    if((this->GetNextDay() == rhs.GetNextDay()) && (this->GetHours() < rhs.GetHours()))
    {
        return true;
    }
    if((this->GetHours() == rhs.GetHours()) && (this->GetMinutes() < rhs.GetMinutes()))
    {
        return true;
    }
    return false;
}