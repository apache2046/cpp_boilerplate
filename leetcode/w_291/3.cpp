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
        set<vector<int>> ret;

        vector<int>prefix(nums.size()+1);
        // if(nums[0] % p == 0)
        //     prefix[0] = 1;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] % p == 0)
                prefix[i+1] = prefix[i] +1;
            else
                prefix[i+1] = prefix[i];
            cout << i <<"_" << prefix[i+1] << endl;
        }
        cout << prefix[4] <<"," << prefix[0] << endl;
        // for (int l=0; l<=nums.size()-1; l++){
        //     for(int i=l; i<nums.size(); i++){
        //         cout << l << ", " << i <<", " << prefix[i+1] - prefix[i+1-l] << endl;
        //         int t = prefix[i+1] - prefix[i+1-l];
        //         if(t <= k){
        //             cout << l << ":" << i << endl;
        //             ret.insert(vector<int>(nums.begin()+i-l, nums.begin()+i +1));
        //         }
        //     }
        // }
        for(int i=0; i< nums.size(); i++){
            for(int j = i+1; j<= nums.size(); j++){
                if(prefix[j] - prefix[i] <= k) {
                    ret.insert(vector<int>(nums.begin()+i, nums.begin()+j));
                } else{
                    break;
                }
            }
        }
        for(auto &item : ret){
            for(int v : item)
                cout << v << " ";
            cout << endl;
        }
        return ret.size();

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
    k = 4;
    p = 1;
    ret = sln.countDistinct(nums, k, p);
    cout << ret << endl;

}