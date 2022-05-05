#include "../stdc++.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -10000000)));
        dp[0][1][0] = -prices[0];
        dp[0][0][0] = 0;
        for(int i = 1 ; i< prices.size(); i++){
            dp[i][1][0] = max(-prices[i], dp[i-1][1][0]);
            dp[i][0][0] = 0;
        }
        for(int i = 1; i< prices.size(); i++){
            int cur = prices[i];
            for(int j = 1; j <= k; j++){
                dp[i][0][j] = max(dp[i-1][0][j], dp[i-1][1][j-1] + cur);
                dp[i][1][j] = max(dp[i-1][1][j], dp[i-1][0][j] - cur);
                cout << i<<" 0 " << j <<":" << dp[i][0][j] << endl;
                cout << i<<" 1 " << j <<":" << dp[i][1][j] << endl;
            }
        }
        int ret = 0;
        do {
            ret = max(ret, dp[prices.size()-1][0][k]);
            k--;
        } while(k>=0);
        return ret;
    }
};

int main(){

    Solution sln;

    int k=4;
    vector<int> input1 {1,2,4,2,5,7,2,4,9,0};

    int ret = sln.maxProfit(k, input1);

    cout << ret << endl;

}