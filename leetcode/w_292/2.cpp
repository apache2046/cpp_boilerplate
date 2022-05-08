#include "../..//stdc++.h"


using namespace std;


struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int ret;
    pair<int, int> dfs(TreeNode * root){
        if(root == nullptr)
            return make_pair(0, 0);
        auto [lsum, lcnt] = dfs(root->left);
        auto [rsum, rcnt] = dfs(root->right);
        int sum = lsum + rsum + root->val;
        int cnt = lcnt + rcnt + 1;
        if(sum / cnt == root->val)
            ret ++;
        
        return make_pair(sum, cnt);
    }
    int averageOfSubtree(TreeNode* root) {
        ret = 0;
        dfs(root);
        return ret;
    }
};

int main()
{
    // string number = "123";
    // char digit = '3';

    // string s = "abc";

    // Solution sln;
    // string ret = sln.removeDigit(number, digit);
    // cout << ret << endl;


}