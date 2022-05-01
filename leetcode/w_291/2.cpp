#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> m;
        int prev  = INT_MAX;
        for(int i=0 ;i < cards.size(); i++){
            int v = cards[i];
            if(m.count(v) != 0){
                prev = min(prev, i-m[v]+1);
            }
            m[v] = i;
        }

        // for(int l=1; l<cards.size()-1; l++){
        //     for (int i = 0; i<cards.size()-l; i++){
        //         if(cards[i] == cards[i+l])
        //             return l+1;
        //     }
        // }
        if (prev == INT_MAX)
            return -1;
        else
            return prev;
        
    }
};

int main()
{
    vector<int> input1 {3,4,2,3,4,7};

    Solution sln;
    int ret = sln.minimumCardPickup(input1);
    cout << ret << endl;

    vector<int> input2 {1,0,5,3};
    ret = sln.minimumCardPickup(input2);
    cout << ret << endl;




}