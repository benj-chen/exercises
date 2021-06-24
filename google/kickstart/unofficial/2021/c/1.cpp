#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)

#define vt vector
using vi = vt<int>;
using vl = vt<ll>;
using vp = vt<pii>;
using vpll = vt<pll>;

using vvi = vt<vi>;
using vvl = vt<vl>;

#define alg_type vi // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>
#define f first
#define s second

int ceildiv(const int& divid, const int& divis) {
    return (divid/divis)+bool(divid%divis);
}
void solve() {
    int k,n,half;
    string s, half_pal;
    cin >> n >> k >> s;
    half=ceildiv(n,2);
    // if the back half reversed is lexicographically smaller, reverse
    // reverse(begin(s),end(s));
    int multiply[half];
    FOR(i,0,n) {
        multiply[i]=s[i]-'a'+1;
    }
    ll res=1;
    for (int i: multiply) {
        cerr << i << " ";
        res*=i;
    }
    cout << res << endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;T++;FOR(t,1,T) {
        cout << "Case #" << t << ": ";
        solve();
    }
}