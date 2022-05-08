#include "../..//stdc++.h"


using namespace std;

class Solution {
public:
    int countTexts(string pressedKeys) {
        int ret = 1;
        int m = 1e9 + 7;
        vector<long long> fib4(100001);
        fib4[1] = 1;
        fib4[2] = 2;
        fib4[3] = 4;
        fib4[4] = 8;
        for(int i = 5; i<100001; i++) {
            fib4[i] = (fib4[i-1] + fib4[i-2] + fib4[i-3] + fib4[i-4]) % m;
        }
        vector<long long> fib3(100001);
        fib3[1] = 1;
        fib3[2] = 2;
        fib3[3] = 4;
        for(int i = 4; i<100001; i++) {
            fib3[i] = (fib3[i-1] + fib3[i-2] + fib3[i-3]) % m;
        }

        int last = pressedKeys[0];
        int cnt = 1;
        for(int i = 1; i < pressedKeys.size(); i++){
            int cur = pressedKeys[i];
            if(cur == last) {
                cnt ++;
            } else {
                if(last == '7' || last == '9')
                    ret = ret * fib4[cnt] % m;
                else
                    ret = ret * fib3[cnt] % m;
                cnt = 1;
                last = cur;
            }
        }
        if(last == '7' || last == '9')
            ret = ret * fib4[cnt] % m;
        else
            ret = ret * fib3[cnt] % m;

    
        return ret;
        
    }
};

int main()
{
    string input1 = "22233";

    Solution sln;
    int ret = sln.countTexts(input1);
    cout << ret << endl;

    string input2 = "222222222222222222222222222222222222";
    ret = sln.countTexts(input2);
    cout << ret << endl;

    string input3 = "444479999555588866";
    ret = sln.countTexts(input3);
    cout << ret << endl;
}