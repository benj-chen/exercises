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
int factors_len(int q) {
    int res=0;
    int i=1;
    while (i*i<=q) {
        if (q%i==0) {
            res++;
            if (q/i!=i) res++;
        }
        i++;
    }
    return res;
}
int main() {
    ll sum=0;

    for (int i=1;true;i++) {
        sum+=i;
        if (factors_len(sum)>500) {
            cout << sum << endl;
            return 0;
        }
    }
    vi v = factors(36);
    for (int i: v) cout << i << endl;
    cout << endl;
    v = prime_factors(36);
    for (int i: v) cout << i << endl;

}
/*
36=2^2 * 3^3
*/