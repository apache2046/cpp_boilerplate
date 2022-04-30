#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string, int> m ;
        for (int i=1; i<=s.size(); i++){
            m[s.substr(0, i)] = 1;
        }
        int ret = 0;
        for(auto &chk : words){
            if(m[chk] == 1)
                ret ++;
        }

        return ret;
        
    }
};

int main()
{
    vector<string> words {"a","b","c","ab","bc","abc"};
    string s = "abc";

    Solution sln;
    int ret = sln.countPrefixes(words, s);
    cout << ret << endl;

}