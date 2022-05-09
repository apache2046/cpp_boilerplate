#include "../stdc++.h"

struct Node{
    int key;
    int val;
    int freq;
};

// set<Node *, decltype(lm)> s(lm);
class LFUCache {
public:
    int capacity;
    unordered_map<int, list<Node> > freq_table;
    unordered_map<int, list<Node>::iterator> lookup_table;
    int min_freq;

    LFUCache(int capacity) {
        this->capacity = capacity;
        // min_freq = 0;
    }
    
    int get(int key) {
        if(lookup_table.count(key) == 0)
            return -1;
        auto iter = lookup_table[key];
        int freq = iter->freq;
        int val = iter->val;

        iter->freq ++;
        freq_table[freq+1].push_front(*iter);
        lookup_table[key] = freq_table[freq+1].begin();
        freq_table[freq].erase(iter);

        cout <<"E1 " << freq << ": " << freq_table[freq].size() << endl;
        if(freq_table[freq].size() == 0 && freq == min_freq)
            min_freq++;
        
        return val;
    }
    
    void put(int key, int value) {
        if(capacity == 0)
            return;
        if(lookup_table.count(key) == 0) {
            if(lookup_table.size() == capacity){
                cout <<"G1 " << min_freq <<": "<< freq_table[min_freq].size() << endl;
                auto iter = freq_table[min_freq].end();
                iter -- ;
                lookup_table.erase(iter->key);
                freq_table[min_freq].erase(iter);
                cout <<"E2 " << min_freq << ": " << freq_table[min_freq].size() << endl;
            }
            min_freq = 1;
            Node node;
            node.freq = 1;
            node.val = value;
            node.key = key;
            freq_table[1].push_front(node);
            lookup_table[key] = freq_table[1].begin();
        } else {
            auto iter = lookup_table[key];
            int freq = iter->freq;
            iter->val = value;

            iter->freq ++;
            freq_table[freq+1].push_front(*iter);
            lookup_table[key] = freq_table[freq+1].begin();
            freq_table[freq].erase(iter);
            cout <<"E3 " << freq << ": " << freq_table[freq].size() << endl;

            if(freq_table[freq].size() == 0 && freq == min_freq){
                min_freq++;
                cout <<"E3.1 " << min_freq << endl;
            }

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {

    vector<string> ops {"LFUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"};

    vector<vector<int>> oprands {{10},{10,13},{3,17},{6,11},{10,5},{9,10},{13},{2,19},{2},{3},{5,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};

    LFUCache * cache;
    for(int i = 0; i< ops.size(); i++){
        cout <<  ops[i] << ":" << oprands[i][0] << endl;
        if(ops[i] == "LFUCache"){
            cache = new LFUCache(oprands[i][0]);
        } else if(ops[i] == "put") {
            cache->put(oprands[i][0], oprands[i][1]);
        } else if(ops[i] == "get") {
            cache->get(oprands[i][0]);
        }
    }
    return 0;
}