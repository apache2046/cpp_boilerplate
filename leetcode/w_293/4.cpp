
#include "../..//stdc++.h"


using namespace std;


class CountIntervals {
public:
    vector<int> segk;
    vector<int> segm;
    int cnt;
    CountIntervals() {
        cnt = 0;
        segk.resize(1024*1024);
        segm.resize(1024);
    }
    
    void add(int left, int right) {
        if(seg.size() == 0){
            seg.push_back(left);
            seg.push_back(right);
            cnt += right - left + 1;
            return;
        }

        sort(seg.begin(), seg.end());


    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

int main()
{
    return 0;
}