#include "../stdc++.h"


using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ret;
        multiset<int, greater<int>> q;

        auto lm = [](const vector<int>& a, const vector<int>& b){
            if(a[0] != b[0])
                return a[0] < b[0];
            else if(a[1] != b[1])
                return a[1] < b[1];
            else if(a[1] == 0)
                return a[2] > b[2];
            else
                return a[2] < b[2];
        };
        vector<vector<int>> scan;
        for(auto &b: buildings){
            scan.push_back({b[0], 0, b[2]});
            scan.push_back({b[1], 1, b[2]});
        }
        sort(scan.begin(), scan.end(), lm);

        for(auto &i: scan) {
            // cout << i[0] << ":" <<i[1] << ":" << i[2] << endl;
            if(i[1] == 0){
                q.insert(i[2]);
                int sky = *(q.begin());
                // cout << "G1 " << sky << endl;
                if(ret.empty() || ret.back()[1] != sky)
                    ret.push_back({i[0], sky});
            } else {
                q.erase(q.find(i[2]));
                int sky = *(q.begin());
                // cout << "G2 " << sky << endl;
                if(ret.back()[1] != sky)
                    ret.push_back({i[0], sky});
            }
        }

        return ret;
    }
};
class Solution2 {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            return a.second < b.second; 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);

        vector<int> boundaries;
        for (auto& building : buildings) {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());

        vector<vector<int>> ret;
        int n = buildings.size(), idx = 0;
        for (auto& boundary : boundaries) {
            while (idx < n && buildings[idx][0] <= boundary) {
                que.emplace(buildings[idx][1], buildings[idx][2]);
                idx++;
            }
            while (!que.empty() && que.top().first <= boundary) {
                que.pop();
            }

            int maxn = que.empty() ? 0 : que.top().second;
            if (ret.size() == 0 || maxn != ret.back()[1]) {
                ret.push_back({boundary, maxn});
            }
        }
        return ret;
    }
};


int main() {
    Solution sln;
    vector<vector<int>> ret;
    vector<vector<int>> input1 {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};

    ret = sln.getSkyline(input1);
    for(auto &item: ret){
        cout << item[0] <<":" <<item[1]<<", ";
    }
    cout << endl;   

    input1 = {{0,2,3},{2,5,3}};
    ret = sln.getSkyline(input1);
    for(auto &item: ret){
        cout << item[0] <<":" <<item[1]<<", ";
    }
    cout << endl;   

}