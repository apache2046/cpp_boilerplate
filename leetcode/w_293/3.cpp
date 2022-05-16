#include "../..//stdc++.h"


using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(64);
        for(auto & n : candidates) {
            for(int i = 0 ; i < 32; i++){
                if (n & (1<< i)){
                    bits[i] ++;
                }
            }
        }
        const auto [min, max] = minmax_element(bits.begin(), bits.end());
        return *max;
    }
};

int main()
{

    Solution sln;
    int ret;
    vector<int> input1 {16,17,71,62,12,24,14};
    ret = sln.largestCombination(input1);
    cout << ret << endl;

    vector<int> input2 {8,8};
    ret = sln.largestCombination(input2);
    cout << ret << endl;


}