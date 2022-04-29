#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    // int maxRotateFunction(vector<int> &nums)
    // {
    //     int s = 0;
    //     int max_v = INT32_MIN;
    //     for(int i = 0; i< nums.size(); i++){
    //         int t = 0;
    //         int p = s;
    //         for(int j = 0; j< nums.size(); j++){
    //             t += j * nums[p];
    //             p = (p+1) % nums.size();
    //         }

    //         if(--s < 0)
    //             s = nums.size() - 1;
    //         max_v = max(max_v, t);
    //     }
    //     return max_v;
    // }
    int maxRotateFunction(vector<int> &nums)
    {
        int s = 0;
        int max_v = INT32_MIN;
        int arr_sum = 0;
        int f1 = 0;
        for (int i = 0; i < nums.size(); i++){
            arr_sum += nums[i];
            f1 += i * nums[i];
        }
        
        max_v = f1;

        for (int i = nums.size()-1; i>=1; i--)
        {
            f1 = f1 + arr_sum - (nums.size()) * nums[i];
            max_v = max(max_v, f1);
        }
        return max_v;
    }
};

int main()
{
    Solution sln;
    vector<int> input{4, 3, 2, 6};
    int ret = sln.maxRotateFunction(input);
    cout << ret << endl;
    return 0;
}
