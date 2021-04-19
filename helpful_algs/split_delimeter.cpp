#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>
#define alg_type vi // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>

vector<string> split_delimeter_char(string s, char delim) {
    vector<string> res(1);
    for (char c: s) {
        if (c==delim) res.push_back("");
        else res.back()+=string(1,c);
    }
    return res;
}

vector<string> split_delimeter_string(string s, string delim) {
    vector<string> res;
    const int dl = delim.length();
    for (int i=0;i<s.length()-dl && s.length()>dl;i++) {
        string seg = s.substr(i,dl);
        if (seg==delim) {
            res.push_back(s.substr(0,i));
            s=s.substr(i+dl);
            i=0;
        }
    }
    res.push_back(s);
    return res;
}
int main() {
    return 0;
}