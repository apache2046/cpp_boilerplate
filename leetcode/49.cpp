#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};


class Solution2 {
public:
    tuple<long, long, long> getSig(string &str) {
        long a = 0, b = 0, c=0;
        map<int, int> m;

        for(auto &ch : str){
            m[ch]++;
        }

        for(auto &[k, v] : m){
            if(k-'r' >= 0){
                a |= ((long)v) << ((k-'r') * 7);
            } else if(k-'j' >= 0) {
                b |= ((long)v) << ((k-'j') * 7);
            } else {
                // cout << k <<":" << (k-'a') * 7 << endl;
                c |= ((long)v) << ((k-'a') * 7);
            }
        }

        return {a, b, c};
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;

        map<tuple<long, long, long>, vector<string>> m;
        for(auto &word: strs) {
            auto [a, b, c] = getSig(word);
            m[{a,b,c}].push_back(word);
        }
        for(auto &item : m){
            ret.push_back(item.second);
        }

        return ret;
    }
};