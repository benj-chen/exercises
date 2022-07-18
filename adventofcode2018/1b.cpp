#include <bits/stdc++.h>
using namespace std;
int main() {
    char sign;
    int res=0;
    vi stuff;
    while (cin>>sign) {
        int i;
        cin>>i;
        if (sign=='+') stuff.push_back(i);
        else stuff.push_back(-i);
    }
    set<int> ress;
    ress.insert(0);
    while (true) {
        for (int i: stuff) {
            res+=i;
            int sz = ress.size();
            ress.insert(res);
            if (sz==ress.size()) {
                cout << res << endl;
                return 0;
            }
        }
    }
    cout<<res<<endl;
}