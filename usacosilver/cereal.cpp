#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
#define f first
#define s second
int n,m;
vector<pii> f;
stack<int> ans;
int mann() {
    // make a list of blocked by
    ifstream cin("cereal.in");
    ofstream cout("cereal.out");
    cin >> n >> m;
    f.resize(n);
    for (int i=0;i<n;i++) {
        cin >> f[i].f >> f[i].s;
    }
    // could make essentially a queue for each cereal ID that spits out what its next to-take option would be

}
int main() {
    ifstream cin("cereal.in");
    ofstream cout("cereal.out");
    cin >> n >> m;
    f.resize(n);
    for (int i=0;i<n;i++) {
        cin >> f[i].f >> f[i].s;
    }// sorted cereals
    // consider from the front, add on with each new thing?
    // save answers and print reversed
    // observe that you can reverse the process!
    for (int i=0;i<n;i++) {
        // i is the number to take out, think of this as just a bunch of test cases
        set<int> taken;
        int ct=0;
        for (int j=i;j<n;j++) {
            pii p=f[j];
            if (*taken.lower_bound(p.f)==p.f) {
                // favorite taken
                if (*taken.lower_bound(p.s)!=p.s) {
                    // second f avail
                    taken.insert(p.s);
                    ct++;
                }
                
            }
            else {
                // favorite avail
                ct++;
                taken.insert(p.f);
            }
        }
        cout << ct << endl;
    }

}