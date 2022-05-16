#include "../..//stdc++.h"


using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int spp = 0;
        int ret = 0;
        for(int i=1; i<special.size(); i++){
            ret = max(ret, special[i]- special[i-1]-1);
        }
        ret = max(ret, special.front() - bottom);
        ret = max(ret, top - special.back());




        return ret;
    }
};

int main()
{

    Solution sln;
    int ret;
    vector<int> input1 {4,6};
    ret = sln.maxConsecutive(2, 9, input1);
    cout << ret << endl;

    vector<int> input2 {7,6,8};
    ret = sln.maxConsecutive(6, 8, input2);
    cout << ret << endl;


}