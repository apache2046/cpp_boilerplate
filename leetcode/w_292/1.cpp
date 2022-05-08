#include "../..//stdc++.h"


using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int fmax = -1;
        vector<int> f (10);
        for(int i = 0; i<= num.size()-3; i++){
            int c = num[i] - '0';
            if(f[c] == 1)
                continue;
            if((num[i] == num[i+1]) && (num[i] == num[i+2])){
                c = num[i] - '0';
                fmax = max(fmax, c);
                f[c] = 1;
                i +=2;
            }
        }
        if(fmax < 0)
            return "";
        string s = to_string(fmax);
        return s+s+s;
    }
};

int main()
{
    string num1 = "6777133339";
    string num2 = "2300019";
    string num3 = "42352338";


    Solution sln;
    string ret = sln.largestGoodInteger(num1);
    cout << ret << endl;

    ret = sln.largestGoodInteger(num2);
    cout << ret << endl;

    ret = sln.largestGoodInteger(num3);
    cout << ret << endl;


}