#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int grid_cnt = m * n - guards.size() - walls.size();
        auto lm = [](pair<int, int> a){ return (a.first << 16) + a.second;};
        unordered_map<pair<int, int>, int, decltype(lm)> see(0, lm);
        unordered_map<pair<int, int>, int, decltype(lm)> _walls(0, lm);
        unordered_map<pair<int, int>, int, decltype(lm)> _guards(0, lm);
        for(auto & guard_pos: guards){
            _guards[{guard_pos[0], guard_pos[1]}] = 1;
        }
        for(auto & wall_pos: walls){
            _walls[{wall_pos[0], wall_pos[1]}] = 1;
        }

        // stack<pair<int, int>> stk;
        for(auto & guard_pos: guards){
            int x = guard_pos[1];
            int y = guard_pos[0];
            while(x > 0){
                if(_walls.count({y, x-1}) == 0 && _guards.count({y, x-1}) == 0){
                    see[{y, x-1}] = 1;
                    x -- ;
                } else {
                    break;
                }
            }
            x = guard_pos[1];
            y = guard_pos[0];
            while(x < n-1){
                if(_walls.count({y, x+1}) == 0 && _guards.count({y, x+1}) == 0){
                    see[{y, x+1}] = 1;
                    x ++ ;
                } else {
                    break;
                }
            }
            x = guard_pos[1];
            y = guard_pos[0];
            while(y > 0){
                if(_walls.count({y-1, x}) == 0 && _guards.count({y-1, x}) == 0){
                    see[{y-1, x}] = 1;
                    y -- ;
                } else {
                    break;
                }
            }
            x = guard_pos[1];
            y = guard_pos[0];
            while(y < m-1){
                if(_walls.count({y+1, x}) == 0 && _guards.count({y+1, x}) == 0){
                    see[{y+1, x}] = 1;
                    y ++ ;
                } else {
                    break;
                }
            }
        }
        // for(auto & pos : see) {
        //     cout << pos.first.first << "," << pos.first.second << endl;
        // }
        // cout << endl;
        return grid_cnt - see.size();

    }
};

int main()
{
    int m = 4, n = 6;
    vector<vector<int>> guards {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls {{0,1},{2,2},{1,4}};
    Solution sln;

    int ret = sln.countUnguarded(m, n, guards, walls);

    cout << ret << endl;


}