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

vt<pii> valid;
bool is_valid(int n) {
    for (pii& p: valid) if (n<p.f || n>p.s) return false;
    return true;
}
vector<string> split_delimeter_char(string s, char delim) {
    vector<string> res(1);
    for (char c: s) {
        if (c==delim) res.push_back("");
        else res.back()+=string(1,c);
    }
    return res;
}
vt<vi> tickets; // excludes mine
void get_input1() {
    ifstream in("i16");
    string input;
    while (getline(in,input)) {
        if (input=="") break;
        vs v = split_delimeter_char(input,' ');
        string a = v[v.size()-3],b=v.back();
        v = split_delimeter_char(a,'-');
        valid.push_back(make_pair(stoi(v[0]),stoi(v[1])));
        v = split_delimeter_char(b,'-');
        valid.push_back(make_pair(stoi(v[0]),stoi(v[1])));
        // all of them have "or"
    }

    // my ticket - ignore for now
    getline(in,input); // "your ticket:"
    getline(in,input); // ticket nums
    getline(in,input); // empty
    getline(in,input); // "nearby tickets:"
    while (getline(in,input)) {
        tickets.push_back({});
        vs v = split_delimeter_char(input,',');
        for (string s: v) {
            tickets.back().push_back(stoi(s));
        }
    }
}
void solve1() {
    get_input1();
    
    // ll res=0;
    // for (vi v: tickets) {
    //     for (int i: v) {
            
    //         if (is_valid(i)) {
    //             res+=i;
    //         }
    //     }
    // }
    // cout << res << endl;
}
int main() {
    solve1();
}