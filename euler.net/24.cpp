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
    vi v = {0,1,2,3,4,5,6,7,8,9};
    FOR(i,0,1e6-1) {
        next_permutation(v.begin(),v.end()); // this feels like cheating but hey
    }
    for (int i: v) cout << i;
    cout << endl;
}