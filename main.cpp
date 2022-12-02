#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main () {
    std::string line;
    std::ifstream myfile ("input.txt");
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

    return 0;
}