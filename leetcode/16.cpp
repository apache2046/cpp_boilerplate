#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
    }
};

int main()
{
    Solution sln;
    vector<int> input{-1, 2, 1, -4};
    int ret = sln.threeSumClosest(input, 1);
    cout << ret << endl;

    input = {0, 0, 0};
    ret = sln.threeSumClosest(input, 1);
    cout << ret << endl;
    return 0;
}
