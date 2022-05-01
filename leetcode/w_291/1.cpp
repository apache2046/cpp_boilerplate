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
    string removeDigit(string number, char digit) {
        int d = digit - '0';
        int lp = 0;
        for (int i = 0; i<number.size(); i++){
            if(number[i] == digit){
                lp = i;
                if(i<number.size()-1 && number[i+1] - '0' > d) {
                    string f1 = number.substr(0, i);
                    string f2 = number.substr(i+1);
                    return f1 + f2;
                }

            }
        }
        string f1 = number.substr(0, lp);
        if(lp < number.size()-1)
            f1 +=  number.substr(lp+1);
        return f1;
    }
};

int main()
{
    string number = "123";
    char digit = '3';

    string s = "abc";

    Solution sln;
    string ret = sln.removeDigit(number, digit);
    cout << ret << endl;

    number = "1231";
    digit = '1';
    ret = sln.removeDigit(number, digit);
    cout << ret << endl;


    number = "551"; 
    digit = '5';
    ret = sln.removeDigit(number, digit);
    cout << ret << endl;

    number = "133235"; 
    digit = '3';
    ret = sln.removeDigit(number, digit);
    cout << ret << endl;


}