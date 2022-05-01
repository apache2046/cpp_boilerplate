#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>


using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int dn = 0;
        set<int> s;
        
        for (auto &n : nums){
            if(n % p == 0)
                dn ++;
            else
                s.insert(n);
            
        }

        int r = s.size();
        int sum; 
        for(int i = 0; i<=k ; i++){
            if(dn < i)
                break;
            
        }

    }
};

int main()
{
    vector<int> nums = {2,3,3,2,2};
    int k = 2, p = 2;

    Solution sln;
    int ret = sln.countDistinct(nums, k, p);
    cout << ret << endl;

    nums = {1,2,3,4};
    int k = 4, p = 1;
    int ret = sln.countDistinct(nums, k, p);
    cout << ret << endl;

}