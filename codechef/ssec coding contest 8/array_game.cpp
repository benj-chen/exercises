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

int main() {
    int n,m;
    cin >> n >> m;
    int a[n];
    FOR(i,0,n) cin >> a[i];
    int maxsz=0;
    for (int i=0;i<n-m+1;i++) {
        set<int> s(a+i,a+i+m);
        maxsz=fmax(maxsz,s.size());
    }
    cout << maxsz << endl;
}