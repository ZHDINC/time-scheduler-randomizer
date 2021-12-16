#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<filesystem>
#include<random>
#include"clock.h"
#include"parserutilities.h"
#include"scheduleitem.h"

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
        std::vector<std::string> lineItemList = ParserUtilities::LineItemParser(str, ',', false);
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
    std::string endTimeFull;
    int hourEnd, minuteEnd;
    bool printingSchedule = true;
    std::cout << "Start time: ";
    // std::cin >> hourStart >> minuteStart;
    std::getline(std::cin, startTimeFull);
    // Clock startClock{hourStart, minuteStart, false};
    Clock startClock{startTimeFull};
    std::cout << "End time: ";
    std::getline(std::cin, endTimeFull);
    //std::cin >> hourEnd >> minuteEnd;
    // Clock endClock{hourEnd, minuteEnd, true};
    Clock endClock{endTimeFull};
    std::cout << "Inputted times: Start: " << startClock.GetHours() << ":" << startClock.GetMinutes() << " End: " << endClock.GetHours() << ":" << endClock.GetMinutes() << "\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, list.size() - 1);
    while(printingSchedule)
    {
        ScheduleItem current = list[distrib(gen)];
        std::cout << std::setw(2) << std::setfill('0') << startClock.GetHours() << ":" << std::setw(2) << std::setfill('0') << startClock.GetMinutes() << " " << current.Title() << '\n';
        startClock.AddMinutes(current.Duration());
        if(startClock > endClock)
        {
            printingSchedule = false;
        }
    }
}