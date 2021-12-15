#include<string>

class ScheduleItem
{
    std::string category;
    std::string title;
    int duration;
public:
    ScheduleItem(std::string category, std::string title, int duration) : category{category}, title{title}, duration{duration} {}
    ScheduleItem() {};
    ~ScheduleItem() {};

    std::string Category() const { return category; }
    std::string Title() const { return title; }
    int Duration() const { return duration; }
};