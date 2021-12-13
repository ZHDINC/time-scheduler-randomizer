#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<filesystem>

class ScheduleItem
{
    std::string category;
    std::string title;
    int duration;
public:
    ScheduleItem(std::string category, std::string title, int duration) : category{category}, title{title}, duration{duration} {}
    ~ScheduleItem() {};

    std::string Category() const { return category; }
    std::string Title() const { return title; }
    int Duration() const { return duration; }
};

int main()
{
    std::string filename{".\\schedule.txt"};
    std::ifstream f;
    std::vector<ScheduleItem> list;
    std::cout << "Current path is " << std::filesystem::current_path() << '\n';
    std::string str{};
    f.open(filename);
    if(!f.is_open())
    {
        std::cout << "File open failed!\n";
    }
    bool fetchCategoryTitle = true;
    std::string currCat;
    std::string currTitle;
    std::string durBeforeParse;
    int currDur;
    while(std::getline(f, str))
    {
        std::cout << "Fetching...\n";
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
        bool switchToDur = false;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == ',')
            {
                switchToDur = true;
                continue;
            }
            if(!switchToDur)
            {
                currTitle += str[i];
                //std::cout << "Current Title: " << currTitle << '\n';
            }
            if(switchToDur)
            {
                if(str[i] == ' ')
                {
                    continue;
                }
                durBeforeParse += str[i];
                //std::cout << "Duration before parse: " << durBeforeParse << '\n';
            }
        }
        currDur = stoi(durBeforeParse);
        ScheduleItem tempItem{currCat, currTitle, currDur};
        std::cout << "Temporary Item: " << tempItem.Category() << ", " << tempItem.Title() << ", " << tempItem.Duration() << " minutes\n";
        currTitle = "";
        durBeforeParse = "";
        list.push_back(tempItem);
    }

    for(ScheduleItem s : list)
    {
        std::cout << s.Category() << ", " << s.Title() << ", " << s.Duration() << " minutes\n";
    }
}