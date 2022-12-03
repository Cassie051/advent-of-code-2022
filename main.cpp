#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

void day1()
{
    std::string line;
    std::ifstream myfile ("input/day1.txt");
    if (myfile.is_open())
    {
        std::vector<int> elfs;
        int calorie_counter = 0, calorie = 0;
        int is_same, max;
        int max_elfs_num = 3, max_elfs_sum = 0;
        while(getline(myfile, line))
        {
            is_same = line.compare("");
            if(is_same == 0)
            {
                elfs.push_back(calorie_counter);
                calorie_counter = 0;
            }
            else
            {
                std::stringstream line_stream(line);
                line_stream >> calorie;
                calorie_counter += calorie;
            }
        }
        myfile.close();
        for (int i=0; i < max_elfs_num; i++)
        {
            max = *std::max_element(elfs.begin(), elfs.end());
            max_elfs_sum += max;
            elfs.erase(std::remove(elfs.begin(), elfs.end(), max), elfs.end());
        }
        std::cout << "Max calories values: " << max_elfs_sum << std::endl; 
    }
    else std::cout << "Unable to open file"; 
}

int whatWasPickedScore(char RPS_option)
{
    if (RPS_option == 'X' || RPS_option == 'A')
        return 1;
    else if (RPS_option == 'Y' || RPS_option == 'B')
        return 2;
    else if (RPS_option == 'Z' || RPS_option == 'C')
        return 3;
    else
        return 0;
}

char whatToDo(char RPS_get, char RPS_response)
{
    if (RPS_response == 'X')
    {
        if(RPS_get == 'A')
            return 'C';
        if(RPS_get == 'B')
            return 'A';
        if(RPS_get == 'C')
            return 'B';
    }
    else if (RPS_response == 'Y')
        return RPS_get;
    else if (RPS_response == 'Z')
    {
        if(RPS_get == 'A')
            return 'B';
        if(RPS_get == 'B')
            return 'C';
        if(RPS_get == 'C')
            return 'A';
    }
}

int forRoundScore(char RPS_response)
{
    if(RPS_response == 'X')
        return 0;
    else if(RPS_response == 'Y')
        return 3;
    else if(RPS_response == 'Z')
        return 6;
}

int forRoundScore(char RPS_get, char RPS_response)
{
    if((RPS_get == 'A' && RPS_response == 'X') || (RPS_get == 'B' && RPS_response == 'Y') || (RPS_get == 'C' && RPS_response == 'Z'))
        return 3;
    else if((RPS_get == 'A' && RPS_response == 'Y') || (RPS_get == 'B' && RPS_response == 'Z') || (RPS_get == 'C' && RPS_response == 'X'))
        return 6;
    else
        return 0;
}

void day2()
{
    std::string line;
    std::ifstream myfile ("./input/day2.txt");
    long int total_score = 0;
    if (myfile.is_open())
    {
        while(getline(myfile, line))
        {
            // total_score += forRoundScore(line[0], line[2]) + whatWasPickedScore(line[2]);
            total_score += whatWasPickedScore(whatToDo(line[0], line[2])) + forRoundScore(line[2]);
        }
        myfile.close();
        std::cout << "Total score: " << total_score << std::endl; 
    }
    else std::cout << "Unable to open file"; 
}

int main () 
{
    day2();
    return 0;
}