#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define alg_type int // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>
#define f first
#define s second

void solve() {
    int n,k,p;
    cin >> n >> k >> p;
    vt<vi> stacks(n,vi(k));
    FOR(i,0,n) {
        cin >> stacks[i][0];
        FOR(j,1,k){
            cin >> stacks[i][j];
            stacks[i][j]+=stacks[i][j-1];
        }
    }
    

}
int main() {
    int T;cin>>T;T++;FOR(t,1,T) {
        cout << "Case #" << t << ": ";
        solve();
    }
}