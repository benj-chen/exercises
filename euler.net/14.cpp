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

// dynamic program your way to success, eventually
int count_steps(ul n) {
    int t=1;
    while(n!=1) {
        
        if (n>>1<<1==n) n>>=1;
        else n=n*3+1;
        t++;
    }
    return t;
}
int main() {
    pii l = make_pair(0,0);
    for (int i=1;i<1000000;i++) {
        int f = count_steps(i);
        if (f>l.s) {
            l = make_pair(i,f);
        }
    }
    cout << l.f << endl;
}