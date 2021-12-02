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

ll ceildiv(ll divid, ll divis) {
    return (divid/divis)+bool(divid%divis);
}
ll sumrange(ll st, ll end) {
    assert (end>=st);
    return (st+end)*(end-st+1)>>1;
}

pii divmod(ll divid, ll divis) {
    return make_pair(divid/divis, divid%divis);
}

int main() {
}