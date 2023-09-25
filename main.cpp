#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

int findTheMostSuitableIndexToRemove  (std::vector<int>& vec) // greedy algo
{
    int index = 0;
    int size = vec.size();
    int min_diff = INT_MAX; // minimal variation between min/max
    for (int i = 0; i < size; i++) {
        std::vector<int> temp_arr = vec; // create copy af array to work with
        temp_arr.erase(temp_arr.begin() + i); // remove element with i index
        int diff = *std::max_element(temp_arr.begin(), temp_arr.end()) 
                 - *std::min_element(temp_arr.begin(), temp_arr.end()); // find variation betwenn min/max

        if (diff < min_diff) {
            min_diff = diff; // update minimal min/max variation
            index = i;
        }
    }
    return index;
}

int main ()
{
    int timberAmmount, timbersToRemove, minimalVariation = 0; // timber ammount is "n" from task text, and "k" is timbers to remove
    std::vector<int> arr;

    std::cin >> timberAmmount >> timbersToRemove;

    if (timberAmmount > 200000 || timberAmmount < 0) // check for right ammount of timbers
    {
        std::cout << "Wrong ammount of timbers";
        return 0;
    }

    if (timbersToRemove > timberAmmount || timbersToRemove < 0) // check for right ammount of timbers to remove
    {
        std::cout << "Wrong ammount of timbers to remove";
        return 0;
    }
    

    for (size_t i = 0; i < timberAmmount; i++) // filling array of timber lenghts from keyboard
    {
        int tmp;
        std::cin >> tmp;
        arr.push_back(tmp);
    }

    if (timbersToRemove == 0) // if there is no timbers thas needs to be removed, than cout straight min/max difference
    {
        minimalVariation = *std::max_element(arr.begin(), arr.end()) - *std::min_element(arr.begin(), arr.end()); // находим разницу
    }
    else
    {
        for (size_t i = 0; i < timbersToRemove; i++)
            {
                arr.erase(arr.begin() + findTheMostSuitableIndexToRemove(arr));
            }
    }

    std::cout << minimalVariation;
    return 0;
}
