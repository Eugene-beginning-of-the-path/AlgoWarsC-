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
        const int size = nums.size();
        for (size_t i = 0; i < size; i++)
            for (size_t j = i+1; j < size; j++)
            {
                if (nums[i] + nums[j] == target)
                    return std::vector<int> {(int)i, (int)j};
            }

        return vector<int>{-1,-1};
    }

    //LeetCode: Plus One
    vector<int> plusOne(vector<int>&& digits) {
       // 495999
        // 123
        // 9 -> 10
        // 99
        size_t size = v.size();
        for (int i = size-1; 0 <= i; i--)
        {
            if (i == size-1)
                v[i]++;

            if (v[i] == 10)
            {
                v[i] = 0;
                if (i != 0)
                    v[i - 1]++;
                else //if i == 0
                {
                    v.push_back(0);
                    v[0] = 1;
                }

            }
        }
        return v;
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

//Wikipedia(ru): Vector(C++) 
void vectorMatrix()
{
    mtrx m(COLUMNS, std::vector<int>(ROWS));
    
        unsigned i = 0;
        for (std::vector<std::vector<int>>::iterator iterV1 = m.begin(); iterV1 < m.end(); iterV1++)
            {
                i = 0;
                for (std::vector<int>::iterator iterV2 = (*iterV1).begin(); iterV2 < (*iterV1).end(); iterV2++, i++)
                {
                    (*iterV2) = i;
                }
            }
    
        for (std::vector<std::vector<int>>::iterator v1 = m.begin(); v1 < m.end(); v1++)
            {
                std::cout << std::endl;
                for (std::vector<int>::iterator v2 = (*v1).begin(); v2 < (*v1).end(); v2++)
                std::cout << *v2 << std::endl;
            }
    
        m.pop_back();
        m.erase(m.begin());
    
        for (std::vector<std::vector<int>>::iterator v1 = m.begin(); v1 < m.end(); v1++)
        {
            (*v1).pop_back();
            (*v1).erase((*v1).begin());
        }
    
        std::cout << "\n===============\n";
        for (std::vector<std::vector<int>>::iterator v1 = m.begin(); v1 < m.end(); v1++)
            {
                std::cout << std::endl;
                for (std::vector<int>::iterator v2 = (*v1).begin(); v2 < (*v1).end(); v2++)
                std::cout << *v2 << std::endl;
            }
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < *(argv[1])-(int)'0'; i++) 
        run_case(i+1);

    return 0;
}
