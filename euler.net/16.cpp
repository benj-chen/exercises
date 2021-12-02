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
string str_multiplication(string a, string b) {
    // do the grade-school style, not too sure how I'd do this without resorting to bit representation which is probably slow anyway with conversion
    // O(a.size() * b.size())
    vt<string> sums;
    int carry_over=0;
    reverse(a.begin(),a.end());
    for (int i=b.size()-1;i>-1;i--) {
        string sum;
        for (char c:a ) {
            string s= to_string((c-'0')*(b[i]-'0')+carry_over);
            if (s.size()>1) {
                // take the last digit
                carry_over=stoi(s.substr(0,s.size()-1));
            }
            else carry_over=0;
            sum=string(1,s.back())+sum;
        }
        sums.push_back(to_string(carry_over)+sum);
        carry_over=0;
    }

    string res;
    for (int i=0;i<sums.size();i++) res=str_addition(res,sums[i]+string(i,'0'));
    return res;
}
int main() {
    string res="1";
    for (int i=0;i<1000;i++) {
        res=str_multiplication(res,"2");
    }
    int sum=0;
    for (char c: res) {
        sum+=c-'0';
    }
    cout << sum << endl;
}