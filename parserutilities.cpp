#include"parserutilities.h"

namespace ParserUtilities
{
    std::vector<std::string> LineItemParser(std::string str, char separator, bool spaceIsSeparator)
    {
        std::vector<std::string> tempVector;
        bool letterDetection = true;
        std::string current;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == separator)
            {
                letterDetection = false;
                tempVector.push_back(current);
                current = "";
                continue;
            }
            if(spaceIsSeparator)
            {
                if(str[i] == ' ')
                {
                    letterDetection = false;
                    tempVector.push_back(current);
                    current = "";
                    continue;
                }
            }
            if(!spaceIsSeparator)
            {
                if(!letterDetection && str[i] == ' ')
                {
                    continue;
                }
                if(!letterDetection && str[i] != ' ')
                {
                    letterDetection = true;
                }
            }
            if(spaceIsSeparator)
            {
                if(!letterDetection && str[i] != ' ')
                {
                    letterDetection = true;
                }
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
        // for(std::string s : tempVector)
        // {
        //     std::cout << s << '\n';
        // }
        return tempVector;
    }
}