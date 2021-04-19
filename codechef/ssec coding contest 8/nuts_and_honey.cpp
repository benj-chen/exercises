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
vi factor(int q, vi prev_factors) {
    if (q>>1<<1==q) {
        prev_factors.push_back(2);
        factor(q>>1,prev_factors);
    }
    // sieve factorization isn't necessary probably
    for (int i=3;i<q;i++) {
        if (q%i==0) {
            prev_factors.push_back(i);
            q/=i;
            factor(q,prev_factors);
        }
    }
    return prev_factors;
}
int main() {
    int T;
    cin >> T;
    FOR(q,0,T) {
        int a,b;
        cin >> a >> b;
        // find gcd
        vi factora = factor(a,{}),factorb=factor(b,{});
        int minsize=fmin(factora.size(),factorb.size());
        vi togeth_factors;
        for (int q: factora) {
            for (int i=0;i<factorb.size();i++) {
                if (factorb[i]==q) {
                    factorb.erase(factorb.begin()+i);
                    togeth_factors.push_back(q);
                    break;
                }
            }
        }
        int prod=1;
        for (int i: togeth_factors) prod*=i;
        cout << prod << endl;
    }
}