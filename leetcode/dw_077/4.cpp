#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int max_wtime;

    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        max_wtime = 0;

        auto lm = [](pair<int, int> a){ return (a.first << 16) + a.second;};
        unordered_map<pair<int, int>, int, decltype(lm)> fsee(0, lm);
        unordered_map<pair<int, int>, int, decltype(lm)> wall(0, lm);

        vector<vector<int>> fire(m, vector<int>(n, -1));
        queue<tuple<int, int, int>> fireq;
        for(int y = 0; y< m; y++){
            for (int x= 0; x<n; x++){
                if(grid[y][x] == 1) { //fire
                    fire[y][x] = 0;
                    fireq.push({y, x, 0});
                } else if (grid[y][x] == 2) {
                    wall[{y,x}] == 1;
                }
            }
        }

        while(!fireq.empty()){
            auto [y, x, l] = fireq.front(); fireq.pop();
            fire[y][x] = l;
            if(y>0 && fire[y-1][x] == -1 && wall.count({y-1, x}) == 0 && fsee.count({y-1, x}) == 0){
                fireq.push({y-1, x, l+1});
                fsee[{y-1, x}] = 1;
            }
            if(x>0 && fire[y][x-1] == -1 && wall.count({y, x-1}) == 0 && fsee.count({y, x-1}) == 0){
                fireq.push({y, x-1, l+1});
                fsee[{y, x-1}] = 1;
            }
            if(y<m-1 && fire[y+1][x] == -1 && wall.count({y+1, x}) == 0 && fsee.count({y+1, x}) == 0){
                fireq.push({y+1, x, l+1});
                fsee[{y+1, x}] = 1;
            }
            if(x<n-1 && fire[y][x+1] == -1 && wall.count({y, x+1}) == 0 && fsee.count({y, x+1}) == 0){
                fireq.push({y, x+1, l+1});
                fsee[{y, x+1}] = 1;
            }
        }

        // queue<tuple<int, int, int>> skipq;
        // skipq.push({0,0,0});
        // while(!empty(skipq)){

        // }
    
        function<void(int,int,int,vector<vector<int>> &)> dfs;
        dfs = [&](int y, int x, int l, vector<vector<int>> &accessed) {
            cout << y <<":" << x <<":" <<l << endl;
            if(x == n-1 && y == m-1) {
                max_wtime = min(max_wtime, fire[m-1][n-1] - l);
                for(int i=0; i<m; i++){
                    for(int j =0; j<n; j++){
                        if(accessed[i][j] == 1)
                            cout << i <<":" << j << " ";
                    }
                }
                cout <<endl;
                return;
            }
            if(y>0 && fire[y-1][x] > l && wall.count({y-1, x}) == 0 && accessed[y-1][x] == 0){
                accessed[y-1][x] = 1;
                dfs(y-1, x, l+1, accessed);
                accessed[y-1][x] = 0;
            }
            if(x>0 && fire[y][x-1] > l && wall.count({y, x-1}) == 0 && accessed[y][x-1] == 0){
                accessed[y][x-1] = 1;
                dfs(y, x-1, l+1, accessed);
                accessed[y][x-1] = 0;
            }
            if(y<m-1 && fire[y+1][x] > l && wall.count({y+1, x}) == 0 && accessed[y+1][x] == 0){
                accessed[y+1][x] = 1;
                dfs(y+1, x, l+1, accessed);
                accessed[y+1][x] = 0;
            }
            if(x<n-1 && fire[y][x+1] > l && wall.count({y, x+1}) == 0 && accessed[y][x+1] == 0){
                accessed[y][x+1] = 1;
                dfs(y, x+1, l+1, accessed);
                accessed[y][x+1] = 0;
            }

        };

        vector<vector<int>> accessed(m, vector<int>(n));
        dfs(0, 0, 0, accessed);

        return max_wtime;
    }
};

int main()
{
    int m = 4, n = 6;
    vector<vector<int>> input1 {{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
    vector<vector<int>> input2 {{0,0,0,0},{0,1,2,0},{0,2,0,0}};
    Solution sln;

    int ret = sln.maximumMinutes(input1);
    cout << ret << endl;
    
    // ret = sln.maximumMinutes(input2);
    // cout << ret << endl;

}