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
string binary_representation_pos_neg(ll i) {
    if (i<0) return "1"+binary_representation(-i);
    else return "0"+binary_representation(i);
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
int main() {
    int i=0;
    cout << (i<<1) << endl;
    int n;
    cin >> n;
    n++;
    FOR(i,1,n) {
        string s;
        cin >> s;
        cerr << binary_to_integer(s) << endl;
    }

}