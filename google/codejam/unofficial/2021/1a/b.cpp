#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>



void solve() {
    int m; cin >> m;
    ll allsum=0;
    int a,b;
    vi nums;
    FOR(i,0,m) {
        cin >> a >> b;
        allsum+=a*b;
        FOR(j,0,b) nums.push_back(a);
    }
    cout << allsum << endl;
    ll maxim=0;
    // O(2**m)

    cout << maxim << endl;
}
int main() {
    int T;cin>>T;T++;FOR(t,1,T) {
        cout << "Case #" << t << ": ";
        solve();
    }
}