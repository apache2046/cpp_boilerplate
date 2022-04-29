#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string& word, int cnt) {
        string ret;
        string yuan = "aeiouAEIOU";
        if(yuan.find(word[0]) == string::npos) {
            ret = word.substr(1) + word[0];
        } else {
            ret = word;
        }
        ret += "ma";
        for(int i = 0 ; i < cnt; i++)
            ret += 'a';
            
        return ret;
    }
    string toGoatLatin(string sentence) {
        string ret;
        int cnt = 0;
        int p = 0;
        for (int i = 0 ; i < sentence.size(); i++) {
            if(sentence[i] != ' ')
                continue;
            auto word = sentence.substr(p, i-p);
            ret += convert(word, ++cnt) + " ";
            p = i+1;
        }
        auto word = sentence.substr(p);
        ret += convert(word, ++cnt);

        return ret;
    }
};

int main()
{
    Solution sln;
    string sentence = "I speak Goat Latin";
    cout << sln.toGoatLatin(sentence) << endl;

    sentence = "The quick brown fox jumped over the lazy dog";
    cout << sln.toGoatLatin(sentence) << endl;
    return 0;
}