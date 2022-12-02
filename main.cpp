#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main () {
    std::string line;
    std::ifstream myfile ("input.txt");
    if (myfile.is_open())
    {
        std::vector<int> elfs;
        int calorie_counter = 0;
        while(getline(myfile, line))
        {
            bool is_same = line.compare("\n");
            if(!is_same)
            {
                elfs.push_back(calorie_counter);
                calorie_counter = 0;
            }
            else
            {
                std::cout << line << '\n'; 
                calorie_counter += std::stoi(line.c_str());
            }
        }
        myfile.close();
        int max = *std::max_element(elfs.begin(), elfs.end());
        std::cout << "Max calories values: " << max; 
    }
    else std::cout << "Unable to open file"; 

    return 0;
}