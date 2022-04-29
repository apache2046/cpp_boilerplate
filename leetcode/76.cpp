#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<int, int> m;
        unordered_map<int, int> need;
        for (auto &c : t)
        {
            need[c]++;
        }
        int need_w = need.size();
        // cout << need.size() << endl;
        int valid = 0;
        int left = 0, right = 0;
        int minstr_p;
        int minstr_len = INT_MAX;

        while (left < s.size())
        {
            if (valid < need_w && right < s.size())
            {
                int c = s[right];
                m[c]++;
                if (m[c] == need[c])
                    valid++;
                right++;
            }
            else if (valid == need_w)
            {
                if (right - left < minstr_len)
                {
                    minstr_p = left;
                    minstr_len = right - left;
                }
                int c = s[left];

                if (m[c] == need[c])
                    valid--;
                m[c]--;
                left++;
            } else {
                break;
            }
        };
        // cout << need.size() << endl;
        if(minstr_len <= s.size())
            return s.substr(minstr_p, minstr_len);
        else
            return "";
    }
};

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    Solution sln;
    // cout << sln.minWindow(s, t) << endl;
    // s = "a";
    // t = "a";
    // cout << sln.minWindow(s, t) << endl;
    s = "a";
    t = "aa";
    cout << sln.minWindow(s, t) << endl;
    return 0;
}