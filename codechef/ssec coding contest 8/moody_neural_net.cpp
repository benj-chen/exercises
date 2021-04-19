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

int main() {
    int n=0;
    int ct=0;
    string s;
    string res="";
    while (getline(cin,s)) {
        n++;
        string r="";
        FOR(i,1,s.length()) {
            if (s.substr(i-1,2)=="\\n") {
                ct++;
            }
        }
        bool last_was_backslash=false;
        for (char c: s) {
            if (c=='\\') {
                res+="\n";
                last_was_backslash=true;
            }
            else if (last_was_backslash) {
                last_was_backslash=false;
                continue;
            }
            else res+=string(1,c);
        }
        res+="\n";
    }
    res=res.substr(0,res.size()-1);
    cout << ct << endl << n << endl << res << endl;

}