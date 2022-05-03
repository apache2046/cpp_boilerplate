#include "../stdc++.h"

using namespace std;

class Solution {
public:
    string find_tag(string & str, int &start, int &type) {
        int p1=0, p2=0, p3=0, p4=0;
        p1 = str.find('<', start);
        if(p1 == string::npos)
            return "";
        p2 = str.find('>', p1+1);
        if(p2 == string::npos)
            return "";
        p3 = str.find("<![CDATA[", start);
        if(p3 == p1) {
            p4 = str.find("]]>", p3+8);
            if(p4 == string::npos)
                return "";
            type = 2;
            start = p4 +3;
            return "";
        } 

        cout << p1 << ":" << p2 << endl;
        string ret = str.substr(p1+1, p2-p1-1);
        if(ret[0] == '/'){
            ret.erase(0,1);
            type = 1;
        } else
            type = 0;
        start = p2 + 1;
        return ret;
    };

    bool isValid(string code) {
        stack<string> stk;
        int start = 0;
        while(start < code.size()) {
            int type = 0;
            string tag = find_tag(code, start, type);
            // cout << tag << endl;
            if(type == 2){
                if(stk.empty())
                    return false;
                continue;
            }
            
            if(tag.empty() || tag.size()>9)
                return false;
            if (!std::all_of(tag.begin(), tag.end(), [](unsigned char c){ return std::isupper(c); }))
                return false;
            if(type == 0){
               stk.push(move(tag)); 
            } else {
                if(stk.empty() || stk.top()!= tag)
                    return false;
                stk.pop();
            }
            if(stk.empty() && start < code.size())
                return false;
    
        }
        return stk.empty();
    }
};

int main()
{
    Solution sln;
    string input = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
    auto ret = sln.isValid(input);
    cout << ret << endl;

    input = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>";
    ret = sln.isValid(input);
    cout << ret << endl;

    input = "<A>  <B> </A>   </B>";
    ret = sln.isValid(input);
    cout << ret << endl;   

    return 0;
}
