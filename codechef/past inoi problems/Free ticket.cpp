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
int c,f;
vt<vt<pii> > graph;
int main() {
    cin >> c >> f;
    graph.resize(f);
    FOR(i,0,f) {
        int a,b,c; cin >> a >> b >> c;
    }
}