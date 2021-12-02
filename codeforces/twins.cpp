#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
using pii = pair<int,int>;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vt<int>
#define vvi vt<vi>
#define alg_type int // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>
#define f first
#define s second

string zfill(string s, int size) {
    return string(size-s.length(),'0')+s;
}
string binary_representation(ll i) {
    // i must be positive
    if (!i) return "0";
    assert (i>0);
    string res="";
    while (i) {
        res+=to_string(i>>1<<1!=i);
        i>>=1;
    }
    reverse(begin(res),end(res));
    return res;
}
ll binary_to_integer(string s) {
    // s is made of 1s and 0s
    for (char c: s) if (c!='1' && c!='0') return 0;
    reverse(begin(s),end(s));
    ll res=0,counter=1;
    for (char c: s) {
        if (c=='1') res+=counter;
        counter<<=1;
    }
    return res;
}
vt<alg_vec_type> powerset(const alg_vec_type& l) {
    // generate all subsets of a vector
    int sz = l.size();
    vt<alg_vec_type> res;
    // get binary representation of as many bits as l requires (vec)
    ll mx = pow(2,sz);
    res.resize(mx);
    for (int i=0;i<mx;i++) {
        
        string s = zfill(binary_representation(i),sz);
        // 0 means put in, 1 means don't
        FOR(j,0,sz) {
            if (s[j]=='1') {
                res[i].push_back(l[j]);
            }
        }
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    vi coins(n);
    FOR(i,0,n) cin >> coins[i];
    // like CSES apple division, but I conveniently didn't finish it
    // dynamic program?
    vvi pset1 = powerset(coins); // pset1 and the reverse of pset1 are now opposites of each other by nature of the algorithm - using numbers ascending by 1
    int half=0;
    for (int i: coins) half+=i;
    half/=2;
    pii res = make_pair(100,-1);
    for (vi v: pset1) {
        int sum=0;
        for (int i: v) sum+=i;
        int sh = sum-half;
        if (sh>0 && sh<res.f) {
            res=make_pair(sh,v.size());
        }
    }
    cout << res.s << endl;
    /*
    vt<pii> psetsum;
    for (vi v: pset1) {
        int sum=0;
        for (int i: v) sum+=i;
        psetsum.push_back(make_pair(sum,v.size()));
    }
    int sz = psetsum.size();
    int minsz=n; // max coins is n
    for (vi i: pset1) {for (int j: i) cout << j << " "; cout << endl;}
    cout << endl;
    FOR(i,0,sz) {
        pii a=psetsum[i],b=psetsum[sz-i];
        if (a.f !=b.f) {
            if (a.f>b.f) minsz = min(minsz,a.s);
            else minsz=min(minsz,b.s);
        }
    }
    cout << minsz << endl;
    */
}