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

map<pii,ll> dp;
// pii: {x,y} where x is the horizontal length of the rectangle and y is the vertical length, not that the order matters
ll add_to_dp(int l, int w) {
    pii p = make_pair(l,w);
    if (dp[{l,w}]) return dp[{l,w}];
    if (dp[{w,l}]) return dp[{w,l}];
    if (l && w) {
        dp[p]=add_to_dp(l-1,w) + add_to_dp(l,w-1);
        return dp[p];
    }
    dp[{l,w}]=1;
    return 1;
}

int main() {
    cout << add_to_dp(20,20) << endl;
}