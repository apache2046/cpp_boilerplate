#include "../stdc++.h"

struct Node2 {
    int cnt, time, key, value;

    Node2(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}
    
    bool operator < (const Node2& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};


struct Node{
    int key;
    int val;
    int time;
    int cnt;
};
auto lm =[](const Node* a, const Node *b) {
    if(a->cnt != b->cnt)
        return a->cnt < b->cnt;
    else
        return a->time < b->time;

};
// set<Node *, decltype(lm)> s(lm);
class LFUCache {
public:
    set<Node *, decltype(lm)> s;
    unordered_map<int, Node * > m;
    int capacity;
    int time;

    LFUCache(int capacity):s(lm) {
        this->capacity = capacity;
        time = 0;
    }
    
    int get(int key) {
        if(m[key] == nullptr)
            return -1;
        auto node = m[key];
        s.erase(node);
        node->cnt++;
        node->time = time++;
        s.insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity == 0)
            return;
        if(m[key] == nullptr) {
            auto node = new Node();
            node->key = key;
            node->cnt = 1;
            node->time = time++;
            node->val = value;

            if(s.size() == capacity){
                m.erase((*(s.begin()))->key);
                s.erase(s.begin());
            }
            s.insert(node);
            m[key] = node;
        } else {
            auto node = m[key];
            s.erase(node);
            node->val = value;
            node->cnt++;
            node->time = time++;
            s.insert(node);
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

    return 0;
}