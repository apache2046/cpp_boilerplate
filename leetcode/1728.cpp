#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int m, n, cj, mj;
    vector<string> grid;
    bool can_jump(int x, int y) {
        if(x<0 || y< 0 || x >=n || y>=m)
            return false;
        if(grid[y][x] == '#')
            return false;
        return true;
    }
    int minimax_search(char visit[8][8][8][8][2], int step, bool searchmax, \
                       int ms_x, int ms_y, int cat_x, int cat_y) {
        if(step == 15)
            return -1;
        for(int i=0;i<step; i++)
            cout << "  ";
        printf("M:%d %d, C:%d %d, s:%d\n", ms_x, ms_y, cat_x, cat_y, searchmax);
        if(grid[cat_y][cat_x] == 'F'){
            printf("m:%d %d, c:%d %d\n", ms_x, ms_y, cat_x, cat_y);
            return -1;
        }
        if(cat_x == ms_x && cat_y == ms_y) {
            printf("m:%d %d, c:%d %d\n", ms_x, ms_y, cat_x, cat_y);
            return -1;
        }
        if(grid[ms_y][ms_x] == 'F')
            return 1;
        if(searchmax) {
            int ret = -1;
            for(int x = 1; x <= mj; x++) {
                if(can_jump(ms_x + x, ms_y)) {
                    if(visit[ms_x + x][ms_y][cat_x][cat_y][0] == 0){
                        visit[ms_x + x][ms_y][cat_x][cat_y][0] = 1;
                        ret = max(ret, minimax_search(visit, step+1, false, ms_x+x, ms_y, cat_x, cat_y));
                        visit[ms_x + x][ms_y][cat_x][cat_y][0] = 0;
                        if(ret == 1)
                            return 1;
                    }
                } else
                    break;
            }
            for(int x = -1; x >= -mj; x--) {
                if(can_jump(ms_x + x, ms_y)){
                    if(visit[ms_x + x][ms_y][cat_x][cat_y][0] == 0){
                        visit[ms_x + x][ms_y][cat_x][cat_y][0] = 1;
                        ret = max(ret, minimax_search(visit, step+1, false, ms_x+x, ms_y, cat_x, cat_y));
                        visit[ms_x + x][ms_y][cat_x][cat_y][0] = 0;
                        if(ret == 1)
                            return 1;
                    }
                } else
                    break;
            }
            for(int y = 1; y <= mj; y++) {
                if(can_jump(ms_x, ms_y+y)){
                    if(visit[ms_x][ms_y+y][cat_x][cat_y][0] == 0){
                        visit[ms_x][ms_y+y][cat_x][cat_y][0] = 1;
                        ret = max(ret, minimax_search(visit, step+1, false, ms_x, ms_y+y, cat_x, cat_y));
                        visit[ms_x][ms_y+y][cat_x][cat_y][0] = 0;
                        if(ret == 1)
                            return 1;
                    }
                } else
                    break;
            }
            for(int y = -1; y >= -mj; y--) {
                if(can_jump(ms_x, ms_y+y)){
                    if(visit[ms_x][ms_y+y][cat_x][cat_y][0] == 0){
                        visit[ms_x][ms_y+y][cat_x][cat_y][0] = 1;
                        ret = max(ret, minimax_search(visit, step+1, false, ms_x, ms_y+y, cat_x, cat_y));
                        visit[ms_x][ms_y+y][cat_x][cat_y][0] = 0;
                        if(ret == 1)
                            return 1;
                    }
                } else
                    break;
            }
            for(int i=0;i<step; i++)
                cout << "  ";
            printf("#%d\n", ret);
            return ret;
        } else {
            int ret = 1;
            for(int x = 1; x <= cj; x++) {
                if(can_jump(cat_x + x, cat_y)){
                    if(visit[ms_x][ms_y][cat_x+x][cat_y][1] == 0){
                        visit[ms_x][ms_y][cat_x+x][cat_y][1] = 1;
                        ret = min(ret, minimax_search(visit, step+1, true, ms_x, ms_y, cat_x+x, cat_y));
                        visit[ms_x][ms_y][cat_x+x][cat_y][1] = 0;
                        if(ret == -1)
                            return -1;
                    }
                } else
                    break;
            }
            for(int x = -1; x >= -cj; x--) {
                if(can_jump(cat_x + x, cat_y)){
                    if(visit[ms_x][ms_y][cat_x+x][cat_y][1] == 0){
                        visit[ms_x][ms_y][cat_x+x][cat_y][1] = 1;
                        ret = min(ret, minimax_search(visit, step+1, true, ms_x, ms_y, cat_x+x, cat_y));
                        visit[ms_x][ms_y][cat_x+x][cat_y][1] = 0;
                        if(ret == -1)
                            return -1;
                    }
                } else
                    break;
            }
            for(int y = 1; y <= cj; y++) {
                if(can_jump(cat_x, cat_y+y)){
                    if(visit[ms_x][ms_y][cat_x][cat_y+y][1] == 0){
                        visit[ms_x][ms_y][cat_x][cat_y+y][1] = 1;
                        ret = min(ret, minimax_search(visit, step+1, true, ms_x, ms_y, cat_x, cat_y+y));
                        visit[ms_x][ms_y][cat_x][cat_y+y][1] = 0;
                        if(ret == -1)
                            return -1;
                    }
                } else
                    break;
            }
            for(int y = -1; y >= -cj; y--) {
                if(can_jump(cat_x, cat_y+y)){ 
                    if(visit[ms_x][ms_y][cat_x][cat_y+y][1] == 0) {
                        visit[ms_x][ms_y][cat_x][cat_y+y][1] = 1;
                        ret = min(ret, minimax_search(visit, step+1, true, ms_x, ms_y, cat_x, cat_y+y));
                        visit[ms_x][ms_y][cat_x][cat_y+y][1] = 0;
                        if(ret == -1)
                            return -1;
                    }
                } else
                    break;
            }
            for(int i=0;i<step; i++)
                cout << "  " ;
            printf("#%d\n", ret);
            return ret;

        }
        
    }
    bool canMouseWin(vector<string>& grid, int can_jump, int mouseJump) {
        int r = grid.size();
        int c = grid[0].size();
        int ms_x, ms_y, cat_x, cat_y;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                if(grid[i][j] == 'C'){
                    cat_x = j;
                    cat_y = i;
                    grid[i][j] = '.';
                } else if (grid[i][j] == 'M') {
                    ms_x = j;
                    ms_y = i;
                    grid[i][j] = '.';
                }
        
        char visit [8][8][8][8][2];
        memset(visit, 0, sizeof(visit));
        visit[ms_x][ms_y][cat_x][cat_y][1] = 1;
        m = r;
        n = c;
        cj = can_jump;
        mj = mouseJump;
        this->grid = move(grid);
        int ret = minimax_search(visit, 0, true, ms_x, ms_y, cat_x, cat_y);
        return ret == 1;
    }
};

int main() {
    Solution sln;
    bool ret;
    // vector<string> input1 {"####F","#C...","M...."};
    // ret = sln.canMouseWin(input1, 1, 2);
    // cout << ret << endl;

    vector<string> input2 {"#..C...","M....#.","######.","######.","######.","######F"};
    ret = sln.canMouseWin(input2, 1, 5);
    cout << ret << endl;
    return 0;
}