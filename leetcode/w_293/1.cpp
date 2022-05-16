#include "../..//stdc++.h"


using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ret;
        auto lm = [](vector<int> a){
            long long hash = 0;
            for(auto& item : a){
                hash += (hash << 1 ) + item;
            }
            return hash;
        };
        unordered_map<vector<int>, int, decltype(lm)> see(0, lm);
        vector<int> freq(26);
        fill(freq.begin(), freq.end(), 0);
        for(auto & chr : words[0]){
                freq[chr-'a'] ++;
        }
        see[freq] = 1;
        ret.push_back(words[0]);
        for(int i = 1; i<words.size(); i++) {
            auto &word = words[i];
            fill(freq.begin(), freq.end(), 0);
            for(auto & chr : word){
                freq[chr-'a'] ++;
            }
            if(see.count(freq) == 0){
                ret.push_back(word);
                see.clear();
                see[freq] = 1;
            }
        }

        return ret;
    }
};
int main()
{

    Solution sln;
    vector<string> ret;
    vector<string> input1 {"abba","baba","bbaa","cd","cd"};
    ret = sln.removeAnagrams(input1);
    for(auto &item : ret)
        cout << item << ",";
    cout << endl;


    vector<string> input2 {"a","b","c","d","e"};
    ret = sln.removeAnagrams(input2);
    for(auto &item : ret)
        cout << item << ",";
    cout << endl;
    // ret = sln.divisorSubstrings(430043, 2);
    // cout << ret << endl;

    // ret = sln.divisorSubstrings(30003, 3);
    // cout << ret << endl;

}