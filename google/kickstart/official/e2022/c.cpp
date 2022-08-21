// c
#include<bits/stdc++.h>
#define f(j) for (int i=0;i<j;i++)
using namespace std;
using vi = vector<int>;
using pii = pair<int,int>;
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){out<<'{';if(!v.empty())out<<v.front();for(int i=1;i<v.size();i++)out<<' '<<v[i];out<<'}';return out;}

template<typename T, typename U>
ostream& operator<<(ostream& out, const pair<T,U> p){out << '(' << p.first << ","<<p.second<<')';return out;}

bool is(string s) {
    for (int i=0;i<s.size()/2;i++) {
        if (s[i]!=s[s.size()-1-i]) return false;
    }
    return true;
}
bool revcomp(string a, string b) {
    // b.size() <= a.size()
    for (int i=0;i<b.size();i++) {
        if (b[i] != a[a.size()-1-i]) return false;
    }
    return true;
}
// int main(int argc, char** argv) {ifstream cin(argv[1]);
int main() {
int T;cin>>T;T++;for(int t=1;t<T;t++) {
    int n; cin >> n; string s; cin >> s;
    // step palins: find palins that start at index 0
    // only really need to do half - may be imp for spd later. other half can be mirrored?
    string res;
    // exception: all same let
    for (char c: s) {
        if (c!=s[0]) goto end1;
    }
    res = s[0];
    end1:;
    if (res=="")
    for (int i=n;i>=2;i--) {
        if (!(n%i)) {
            int step = n/i;
            string base = s.substr(0,step);
            if (!is(base)) goto end;
            for (int j=step;j<n;j+=step) {
                if (base != s.substr(j,step)) {
                    goto end;
                }
            }
            // has recurring palindromes
            res = base;
            break;
            end:;
        }
    }
    if (res=="") {
    for (int i=2;i<=n;i++) {
        // is there shit in the middle
        
    }
    }
    if (res=="") {
        res = s;
    }
    cout << "Case #" << t << ": " << res << endl;

    // char let = s[0];
    // for (int i=0;i<n;i++) {
    //     if (s[i]==let) {
    //         string q= s.substr(0,i+1);
    //         if (is(q)){
    //             if (is(s+q)){
    //                 cout << "Case #" << t << ": " << q << endl;break;
                
    //             }
    //         }
    //     }
    // }
    // for(int i=2;i<=n;i++) {
        
    //     string q = s.substr(0,i);
    //     if (is(q)) {
    //         if (is(s+q))
    //         {cout << "Case #" << t << ": "<<q << endl; break;}
            
    //     }
    // }

    // for (int i=(n+1)/2; /* first position that could be the half of the new palin*/ i<n;i++) {
    //     // even halves
    //     if (revcomp(s.substr(0,i-1),s.substr(i+(n%2)-1))) {
    //         string u = s.substr(0,i-1);
    //         reverse(u.begin(),u.end());
    //         cout << "Case #" << t << ": " << u << endl;  
    //     }
    //     // middle
    //     if (revcomp(s.substr(0,i),s.substr(i+(n%2)-1))) {
    //         cout << s.substr(0,i)<<" "<<s.substr(i+(n%2)) << endl;
    //         string u = s.substr(0,i);
    //         reverse(u.begin(),u.end());
    //         cout << "Case #" << t <<": " << u << endl;
    //     }
    //     cout << i << endl;
    // }
}}