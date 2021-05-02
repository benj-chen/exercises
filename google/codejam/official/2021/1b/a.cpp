#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
using pii = pair<int,int>;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>
#define alg_type vi // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>
#define f first
#define s second

void solve() {
    ll a,b,c;
    cin >> a >> b >> c;

    // test a,b,thenc
    // find a way such that at least one number is under 6 hours, adjust each if necessary, then print mins and sec as necessary
    if (a>=12e10) {
        // flip 180 degrees
        a-=12e10;
        b-=12e10;
        c-=12e10;
        if (a<0) a=-a;
        if (b<0) b=-b;
        if (c<0) c=-c;
    }
    cout << a/
    // 12 000 000 000 0


}
int main() {
    int T;cin>>T;T++;FOR(t,1,T) {
        cout << "Case #" << t << ": ";
        solve();
    }
}