#include "../..//stdc++.h"


using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        vector<int> part;
        int nnum = num;
        while(nnum > 0){
            int p  = nnum % 10;
            part.push_back(p);
            nnum /= 10;
        }
        reverse(part.begin(), part.end());
        int l = part.size();
        int ret = 0;
        for(int i = 0; i<= l-k; i++) {
            int bt = 0;
            for(int j = i; j < i+k; j++){
                bt = bt * 10 + part[j];
            }
            // cout << bt << endl;
            if(bt != 0 && num % bt == 0){
                // cout <<":" << bt << endl;
                ret ++;
            }
        }
        return ret;
    }
};
int main()
{

    Solution sln;
    int ret;
    ret = sln.divisorSubstrings(240, 2);
    cout << ret << endl;

    ret = sln.divisorSubstrings(430043, 2);
    cout << ret << endl;

    ret = sln.divisorSubstrings(30003, 3);
    cout << ret << endl;

}