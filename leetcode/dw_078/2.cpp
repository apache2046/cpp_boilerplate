#include "../..//stdc++.h"


using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> presum(nums.size());
        // int total ;
        presum[0] = nums[0];
        for(int i = 1; i< nums.size(); i++)
            presum[i] = presum[i-1] + nums[i];
        long long total = presum.back();
        int ret=0;
        for(int i = 0; i<nums.size()-1; i++){
            if(total - presum[i] <= presum[i])
                ret ++;
        }
        return ret;
    }
};

int main()
{

    Solution sln;
    int ret;
    vector<int> input1 {10,4,-8,7};
    ret = sln.waysToSplitArray(input1);
    cout << ret << endl;

    vector<int> input2 {2,3,1,0};
    ret = sln.waysToSplitArray(input2);
    cout << ret << endl;
}