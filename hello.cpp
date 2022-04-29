#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

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
}