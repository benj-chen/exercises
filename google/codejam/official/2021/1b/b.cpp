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
    int n,a,b,q;
    cin >> n >> a >> b;
    vi v;

    FOR(i,0,n) {
        cin >> q;
        if (q) {
            FOR(j,0,q) v.push_back(i+1);
        }
    }
    // will be sorted
    if (v.empty()) {
        cout << 0 << endl;
        return;
    }
    // simulate
    for (int i=1;true;i++) {
        vi split = {i};
        
    }
    while (/*v.size()!=1*/false) {
        if (v.size()==2) {
            if (v[1]+a==v[0]+b) {
                cout << v[1]+a << endl;
            }
            else {
                cout << "IMPOSSIBLE (size 2)" << endl;
            }
            return;
        }
        // find the two that add
        FOR(i,0,v.size()) {
            FOR(j,i+1,v.size()) {
                if (v[i]+b==v[j]+a) {
                    v.push_back(v[i]+b);
                    v.erase(v.begin()+i);
                    v.erase(v.begin()+j);
                    goto end;
                }
            }
        }
        // none added together
        // add a
        cout << "IMPOSSIBLE (didn't add)" << endl;
        return;
        end:;
        EACH(i,v) cerr << i << " ";
        cerr << endl;

    }

}
int main() {
    int T;cin>>T;T++;FOR(t,1,T) {
        cout << "Case #" << t << ": ";
        solve();
    }
}