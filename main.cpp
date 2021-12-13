#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<filesystem>
#include<random>

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

std::vector<std::string> LineItemParser(std::string str)
{
    std::vector<std::string> tempVector;
    bool letterDetection = true;
    std::string current;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == ',')
        {
            letterDetection = false;
            tempVector.push_back(current);
            current = "";
            continue;
        }
        if(!letterDetection && str[i] == ' ')
        {
            continue;
        }
        if(!letterDetection && str[i] != ' ')
        {
            letterDetection = true;
        }
        if(letterDetection)
        {
            current += str[i];
        }
        if(i == str.size() - 1)
        {
            tempVector.push_back(current);
        }
    }
    return tempVector;
}

int main()
{
    std::string filename{".\\schedule.txt"};
    std::ifstream f;
    std::vector<ScheduleItem> list;
    // std::cout << "Current path is " << std::filesystem::current_path() << '\n';
    std::string str{};
    f.open(filename);
    if(!f.is_open())
    {
        std::cout << "File open failed!\n";
    }
    bool fetchCategoryTitle = true;
    std::string currCat;
    int currDur;
    while(std::getline(f, str))
    {
        // std::cout << "Fetching...\n";
        if(str == "=" || str == "")
        {
            fetchCategoryTitle = true;
            continue;
        }
        if(fetchCategoryTitle)
        {
            fetchCategoryTitle = false;
            currCat = str;
            //std::cout << "Category: " << currCat << '\n';
            continue;
        }
        std::vector<std::string> lineItemList = LineItemParser(str);
        ScheduleItem tempItem{currCat, lineItemList[0], stoi(lineItemList[1])};
        // std::cout << "Temporary Item: " << tempItem.Category() << ", " << tempItem.Title() << ", " << tempItem.Duration() << " minutes\n";
        list.push_back(tempItem);
    }

    // for(ScheduleItem s : list)
    // {
    //     std::cout << s.Category() << ", " << s.Title() << ", " << s.Duration() << " minutes\n";
    // }

    int hourStart, minuteStart;
    std::string startTimeFull;
    int hourEnd, minuteEnd;
    bool printingSchedule = true;
    std::cout << "Start time: ";
    std::cin >> hourStart >> minuteStart;
    std::cout << "End time: ";
    std::cin >> hourEnd >> minuteEnd;
    std::cout << "Inputted times: Start: " << hourStart << ":" << minuteStart << " End: " << hourEnd << ":" << minuteEnd << "\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, list.size() - 1);
    while(printingSchedule)
    {
        ScheduleItem current = list[distrib(gen)];
        std::cout << hourStart << ":" << minuteStart << " " << current.Title() << '\n';
        minuteStart += current.Duration();
        if(minuteStart >= 60 && (hourStart != hourEnd))
        {
            minuteStart -= 60;
            hourStart++;
        }
        if(hourStart == hourEnd)
        {
            if(minuteStart >= minuteEnd)
            {
                printingSchedule = false;
            }
        }
    }
}