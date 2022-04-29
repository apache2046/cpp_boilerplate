#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ret;

        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> po (r, vector<int>(c));
        vector<vector<int>> ao (r, vector<int>(c));

        for(int i=0; i< r; i++) {
            po[i][0] = 1;
            ao[i][c-1] = 1;
        }
        for(int j=0; j< c; j++) {
            po[0][j] = 1;
            ao[r-1][j] = 1;
        }

        stack<pair<int, int>> stk;
        for(int i=0; i< r; i++) {
            stk.push({i, 0});
        }
        for(int j=0; j< c; j++) {
            stk.push({0, j});
        }
        // stk.push({0, 0});


        while(!stk.empty()){
            int i, j;
            tie(i, j) = stk.top(); stk.pop();
            auto fn = [&](int ni, int nj){ 
                if(heights[ni][nj] >= heights[i][j] && po[ni][nj] == 0) {
                    stk.emplace(ni, nj);
                    po[ni][nj] = 1;
                }
            };
            if(j>0)
                fn(i, j-1);
            if(i>0)
                fn(i-1, j);
            if(i+1 < r)
                fn(i+1, j);
            if(j+1 < c)
                fn(i, j+1);


        }
        for(int i=0; i< r; i++) {
            stk.push({i, c-1});
        }
        for(int j=0; j< c; j++) {
            stk.push({r-1, j});
        }
        // stk.push({r-1, c-1});
        while(!stk.empty()){
            int i, j;
            tie(i, j) = stk.top(); stk.pop();
            auto fn = [&](int ni, int nj){ 
                if(heights[ni][nj] >= heights[i][j] && ao[ni][nj] == 0) {
                    stk.emplace(ni, nj);
                    ao[ni][nj] = 1;
                }
            };
            if(j>0)
                fn(i, j-1);
            if(i>0)
                fn(i-1, j);
            if(i+1 < r)
                fn(i+1, j);
            if(j+1 < c)
                fn(i, j+1);

        }
        for(int i=0; i< r; i++) {
            for(int j=0; j< c; j++) {
                if(ao[i][j] == 1 && po[i][j] == 1)
                    ret.push_back({i,j});
                    // ret.emplace_back({i,j});
            }
        }

        return ret;
    }
};
int main(){
    Solution sln;
    vector<vector<int>> input1 {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> ret;
    ret = sln.pacificAtlantic(input1);
    for(auto & r: ret)
        cout << r[0] << " " << r[1] << endl;
    return 0;
}