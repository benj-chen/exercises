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
vt<string> fib={"1","1"};
string zfill(string s, int size) {
    return string(size-s.length(),'0')+s;
}
string zstrip(string s) {
    // strip leading zeroes
    int ind=-1;
    while (s[++ind]=='0') {}
    if (ind==s.size()) return "0";
    return s.substr(ind);
}
// string to int: std::stoi(string)
// int to string: to_string(int)
string str_addition(string a, string b) {
    // both must be positive
    int sz = fmax(a.size(),b.size())+1;
    a=zfill(a,sz);
    b=zfill(b,sz);
    string carry_over = zfill("",sz);
    // 
    int s=sz;
    while (sz--) {
        a[sz]+=b[sz]-'0';
        if (a[sz]>'9') {
            carry_over[sz-1]++;
            a[sz]-=10;
        }
    }
    while (s--) {
        a[s]+=carry_over[s]-'0';
        if (a[s]>'9') {
            a[s]-=10;
            if (s) carry_over[s-1]++;
            else a=string(1,carry_over[0]+1)+a;
        }
    }
    return zstrip(a);
}
void add_fib() {
    fib.push_back(str_addition(fib[fib.size()-1],fib[fib.size()-2]));
}
int main() {
    while (fib.back().length()<1000) add_fib();
    cout << fib.size() << endl;
}