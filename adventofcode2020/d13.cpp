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
int departure;
vi input;
vector<string> split_delimeter_char(string s, char delim) {
    vector<string> res(1);
    for (char c: s) {
        if (c==delim) res.push_back("");
        else res.back()+=string(1,c);
    }
    return res;
}
void get_input() {
    input={};
    ifstream in("i13");
    string inp;
    in >> departure >> inp;
    for (string s: split_delimeter_char(inp,',')) input.push_back((s=="x"? 0: stoi(s)));
}
void solve1() {
    pii shortest=make_pair(INT_MAX,0);
    for (int& i: input) {
        if (i) {
            int mod = i-departure%i;
            if (mod < shortest.f) shortest=make_pair(mod,i);
        }
    }
    cout << shortest.f*shortest.s << endl;
}
ll gcd(ll a, ll b, int offseta, int offsetb) {
    //offset: how much higher does the gcd need to be for b than for a? for 7 and 13 in the sample it is 0 and 1.
    // find the number n such that n%a + offseta == n%b + offsetb
    // n%a == n%b + offsetb - offseta
    // n%a - n%b == offsetb - offseta
    if (a==1) {
        return b+offsetb;
    }
    if (b==1) {
        return a + offseta;
    }
    int offset = offseta-offsetb;
    ll res;
    for (ll i=max(a,b); i<a*b+1;i++) {
        if ((i%a - i%b) == offset) {
            res= i+offseta;
            cout << res << endl;
        }
    }
    return res;
    cout << "error: not found??" << endl;
    cout << a << " " << b << " " << offseta << " " << offsetb << endl;
    throw 1;
}
void solve2() {
    ll sol;
    vi spots;
    int spot=0;
    for (int i: input) {
        if (i) {
            spots.push_back(spot);
        }
        spot++;
    }
    sol = 1;
    spot=input[spots[0]];
    for (int s=1;s<spots.size();s++) {
        cout << spots[s] << endl;
        sol = gcd(sol,input[spots[s]],0,spots[s]-spots[s-1]);
        cout << sol << endl;
        spot++;

    }
    cout << sol << endl;
    cerr << "not implemented" << endl;
}

int main() {
    get_input();
    solve1();
    cout << endl;
    solve2();

    cout << "testing grounds" << endl;
    cout << gcd(7,13,0,-1) << endl << "(should be 51)" << endl;
}