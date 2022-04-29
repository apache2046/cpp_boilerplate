#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
vector<int> _pow {1,2,4,6,8,16,32,64,128};
class Solution {
public:
    vector<vector<int>> _grid;
    int max_level;
    Node* fn(int level, int x, int y){
        if(level < max_level){
            auto tl = fn(level+1, x*2+0, y*2+0);
            auto tr = fn(level+1, x*2+1, y*2+0);
            auto bl = fn(level+1, x*2+0, y*2+1);
            auto br = fn(level+1, x*2+1, y*2+1);
            if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && (tl->val == tr->val == bl->val == br->val)){
                delete tr;
                delete bl;
                delete br;
                return tl;
            } else {
                return new Node(false, false, tl, tr, bl, br);
            }
        }
        return new Node(_grid[y][x], true, nullptr, nullptr, nullptr, nullptr);
    }
    Node* construct(vector<vector<int>>& grid) {
        _grid = move(grid);
        int l = grid.size();
        while(l>1){
            max_level++;
            l=l/2;
        };
        return fn(0, 0, 0);
    }
};



int main() {

}