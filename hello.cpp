// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <numeric>
// #include <bits/stdc++.h>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
#include "stdc++.h"
template<typename T>
void print1d(T & container){
    for(auto & item : container){
        cout << item << " ";
    }
    cout << endl;
}

template<typename T>
void print2d(T & container){
    for(auto & row : container){
        for(auto & col : row)
            cout << col << " ";
        cout << endl;
    }
}

int main()
{

    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    // cout << msg[10000] << endl;
    // A bb;
    // bb->print();

    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    vector<int> a{1, 2, 3, 4, 5, 7};
    int sum = accumulate(a.begin(), a.end(), 0);
    cout << "accumulate:" << sum << endl;

    {
        auto maxv = max_element(a.begin(), a.end());
        auto minv = min_element(a.begin(), a.end());
        cout << "max:" << *maxv << ", min:" << *minv << endl;
    }
    {
        auto [minv, maxv] = minmax_element(a.begin(), a.end());
        cout << "max:" << *maxv << ", min:" << *minv << endl;
    }

    {
        auto p = upper_bound(a.begin(), a.end(), 8);
        cout << p-a.begin() << ":" << a.size() << endl;
    }
    {
        auto [a,b,c,d] = make_tuple(1,2,3,4);
        cout << a << " " << b <<" " << c << " " << d << endl;
        vector<tuple<int, int, int, int>> s;
        s.emplace_back(a,b,c,d);
        {
            tuple<int, int, int, int> tt { 2,3,4,5};
            // auto [a,b,c,d] = tt;
            int a,b,c,d;
            tie(a,b,c,d) = tt;
            cout << a << " " << b <<" " << c << " " << d << endl;
        }
    }

    {
        vector<int> a {1,2,3};
        vector<int> b {1,2,3};
        cout << (a == b) << endl;
        b[1] = 4;
        cout << (a == b) << endl;
        cout << (1==2==3) << endl;
    }

    {
        map<int, int> m;
        cout << m[0] << endl;
        cout << m.size() << endl;
    }

    {
        map<pair<int, int>, int> m;
        m[{1,2}] +=1;
        m[{1,2}] +=1;
        cout << "msize:" << m.size()  <<":" << m[{1,2}] << endl;
    }
    {
        auto lm = [](pair<int, int> a){ return (a.first<<10) + a.second;};
        unordered_map<pair<int, int>, int, decltype(lm)> m(0, lm);
        m[{1,2}] +=1;
        m[{1,2}] +=1;
        cout << "msize:" << m.size()  <<":" << m[{1,2}] << endl;
    }
    {
        auto f = hash<int> {};
        for(int i=0; i< 11; i++)
            cout << f(i*100) << " ";
        cout << endl;
        cout << sizeof(size_t) << endl;
    }

    {
        set<vector<int>> s;
        s.insert(vector<int> {1,2,3});
        s.insert(vector<int> {1,2,3,4});
        s.insert(vector<int> {1,2,3});
        s.insert(vector<int> {2,1,3});
        cout << s.size() << endl;

    }

    {
        auto a="abc", b= "abd";
        cout << (a< b) << endl;
    }
    {
        vector<string>  a= {"abc", "abd", "aba"};
        auto lm = [](string & a, string & b){
            return a.back() < b.back();
        };
        sort(a.begin(), a.end(), lm);
        for(auto &item : a){
            cout << item << " ";
        }
        
        cout << endl;
        string input1 = "ab1";
        // auto _isalpha = [](const char &a){ return a>='a' && a<='z';};
        cout << isalpha(input1.back()) << endl;
    }

    {
        vector<int> a {2,1,3};
        vector<int> b {22,12,32};

        vector<int> c;
        c.insert(c.end(), a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());
        for (auto & n : c)
            cout << n << " ";
        cout << endl;


    }
    {
        struct sum
        {
            sum(int * t):total(t){};
            int * total;
            void operator()(int element)
            {
            *total+=element;
            }
        };

        int total = 0;
        sum s(&total);
        int arr[] = {0, 1, 2, 3, 4, 5};
        std::for_each(arr, arr+6, s);
        cout << total << endl; // prints total = 15;

    }

    {
        vector<int> d1 {2,1,3,4,5};
        print1d(d1);

        vector<vector<int>> d2 {{3,1,2},{0,2,1},{4,5,11}};
        print2d(d2);

        priority_queue<int> q1(d1.begin(), d1.end());
        while(!q1.empty()){
            cout << q1.top() <<" ";
            q1.pop();
        }
        cout << endl;

        priority_queue<int, vector<int>> q2(d1.begin(), d1.end());
    }

    {
        auto lm = [](const tuple<string, int> &a, const tuple<string, int> &b)
        {
            // auto &[v1, o1] = a;
            // auto &[v2, o2] = b;
            // return o1 > o2; // small value first
            return get<1>(a) > get<1>(b);
        };
        priority_queue<tuple<string, int>, vector<tuple<string, int>>, decltype(lm)> q(lm);

        q.push(make_tuple("abc", 2));
        q.push(make_tuple("abc", 1));
        q.push(make_tuple("abc", 3));

        while (!q.empty())
        {
            auto &item = q.top();
            auto &[v, o] = item;
            cout << v << ": " << o << endl;
            q.pop();
        }
    }
}