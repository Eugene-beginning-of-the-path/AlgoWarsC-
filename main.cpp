#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


enum {
    SIXTY = 60
};

// Code Wars - X task
std::string return_hoursMinutesSeconds(long long seconds)
{
    if (seconds > 59)
    {
        int minutes = seconds / SIXTY;
        seconds -= minutes * SIXTY;
        if (minutes > 59)
        {
            int hours = minutes / SIXTY;
            minutes -= hours * SIXTY;
            return (hours < 10 ? ('0' + std::to_string(hours)) : std::to_string(hours))
                + ':' + (minutes < 10 ? ('0' + std::to_string(minutes)) : std::to_string(minutes))
                + ':' + (seconds < 10 ? ('0' + std::to_string(seconds)) : std::to_string(seconds));
        }
        return "00:" + (minutes < 10 ? ('0' + std::to_string(minutes)) : std::to_string(minutes))
            + ':' + (seconds < 10 ? ('0' + std::to_string(seconds)) : std::to_string(seconds));
    }
    return "00:00:" + (seconds < 10 ? ('0' + std::to_string(seconds)) : std::to_string(seconds));
}

using std::vector;
class Solution {
public:
    //LeetCode: Two Sum
    vector<int> twoSum(const vector<int>& nums, int target)
    {
        std::unordered_map<int, int> m;
        vector<int>ans;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        int v1 = 0;
        //[3,2,4], target = 6, answer is [1,2]
        while (v1 < nums.size())
        {
            int val2 = target - nums[v1]; //3
            int v2 = m[val2]; //0
            if (v2 && v2 != v1) {
                ans.push_back(v1);
                ans.push_back(v2);
            }
            if (ans.size() > 0)
                break;
            v1++;
        }
        return ans;
    }

    //LeetCode: Plus One
    vector<int> plusOne(vector<int>&& digits) {
        // 495999
        bool wave = false;
        for (auto el = digits.rbegin(); el < digits.rend(); el++)
        {
            if (*el == 9 && wave == false)
            {
                *el = 0;
                wave = true;
                continue;
            }

            if (*el == 9 && wave == true)
            {
                *el = 0;
                continue;
            }

            if (*el != 9 && wave == true)
            {
                *el++;
                wave = false;
            }

            return digits;
        }

    }

};

using namespace std;

void run_case(int test_case)
{
    int R, C;
    cin >> R >> C; //R is count of rows; C - ? 

    std::vector<std::string> grid(R);
    for (auto& row : grid)
        cin >> row; //writting the line of space from file

    bool has_tree = false;
    for (int r = 0; r < R; r++) //check, Do we have a tree on the field? 
        for (int c = 0; c < C; c++)
            has_tree = grid[r][c] == '^' || has_tree;

    std::cout << "Case #" << test_case << ": ";
    if (R == 1 || C == 1)
    {
        if (has_tree)
        {
            std::cout << "Impossible" << std::endl;
            return;
        }
    }
    std::cout << "Possible" << std::endl;

    if (has_tree)
    {
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                grid[r][c] = '^';
    }

    for (auto& rows : grid)
        std::cout << rows << std::endl;
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < *(argv[1])-(int)'0'; i++) 
        run_case(i+1);

    return 0;
}
