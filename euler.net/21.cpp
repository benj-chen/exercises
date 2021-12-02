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
#define alg_type int // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>
#define f first
#define s second
vi factors(int n)
{
    vi res;
    double sqrtn=sqrt(n);
    for (int i=1; i<=sqrtn; i++)
    {
        if (n%i == 0)
        {
            res.push_back(i);
            if (n/i!=i) res.push_back(n/i);
        }
    }
    return res;
}
int d(int n) {
    int s=0;
    for (int i: factors(n)) s+=i;
    return s-n; // don't count n itself
}
int main() {
    int sum=0;
    FOR(i,1,1e4) {
        int di = d(i);
        if (di==i) continue; // must be different
        int ddi = d(di);
        if (ddi==i) sum+=i;
        cout << i << endl;
    }
    cout << sum << endl;
}