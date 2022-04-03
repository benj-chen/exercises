#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define pq priority_queue
#define f first
#define s second
#define ar array

#define F(i,n)for(int i=0;i<n;i++)
#define FO(i,sa,n)for(int i=sa;i<n;i++)
#define FOR(i,sa,n,sp)for(int i=sa;i<n;i+=sp)

#define all(c)(c).begin(),(c).end()
#define iter(c,ind)(ind<0?(c).end()+ind:(c).begin()+ind)
// iter does c[ind] perfectly on any container assuming one index

using ll = long long;
using vi = vt<int>;
using vl = vt<ll>;
using vvi = vt<vi>;
using vvl = vt<vl>;
using vvvi = vt<vvi>;
using vvvl = vt<vvl>;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

// print vectors with space delimiter
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){if(!v.empty())out<<v.front();for(int i=1;i<v.size();i++)out<<' '<<v[i];return out;}
void ins(string& s, char c, int ind) {
    // in Python, s = s[:ind] + c + s[ind:]
    s = s.substr(0,ind) + string(1,c) + s.substr(ind);
}
// void solve_family(char a, char b) {
//     times++;
//     if (times==40) {
//         return;
//     }
//     char c = m[a<<8+b];
//     if (c) {
//         ct[c]++;
//         solve_family(a,c);
//         solve_family(c,b);
//     }
// }
map<char,long long> ct;
map<int, pair<char,map<char,int>>> m; // int represents 2 characters
void solve(char a, char b, int times) {
if (times) {

}
}
int c2toi(char a, char b) {
    return a<<8+b;
}
int main() {
    string s; cin >> s;
    char a,b; string c; char d;
    while (cin>>a>>b>>c>>d) {
        m[c2toi(a,b)].second[d]=1;
        m[c2toi(a,b)].first=d;
    }
    for (int i=1;i<s.size();i++) {
        solve(c2toi(s[i-1],s[i]));
    }
    // kids only play with family
}
// when solving one family at a time, you can get the result of a pair by looking at index n and index s.size()-n-1
/*
int main() {
    string s;
    cin >> s;
    map<string,char> m;
    string a,b; char c;
    while (cin >> a >> b >> c) m[a]=c;
    for (int j=0;j<10;j++) {


        for (int i=1;i<s.size();i++) {
            c = m[s.substr(i-1,2)];
            if(c) {
                ins(s,c,i);
                i++;
            }
        }
    }
    cout << s.size() << endl;
    map<char,long long> ct;
    for (char c: s) ct[c]++;
    long long max = ct[c], min = ct[c];
    for (pair<char,long long> p: ct) {
        max = fmax(max, p.second);
        min = fmin(min,p.second);
    }
    cout << max-min << " " << max << " " << min <<endl;
    
}
*/
/*
void ins(string& s, char c, int ind) {
    // in Python, s = s[:ind] + c + s[ind:]
    s = s.substr(0,ind) + string(1,c) + s.substr(ind);
}
int main() {
    string s;
    cin >> s;
    map<string,char> m;
    string a,b; char c;
    while (cin >> a >> b >> c) m[a]=c;
    for (int j=0;j<10;j++) {


        for (int i=1;i<s.size();i++) {
            c = m[s.substr(i-1,2)];
            if(c) {
                ins(s,c,i);
                i++;
            }
        }
        cout << s.size() << endl;
    }
    cout << s.size() << endl;
    map<char,long long> ct;
    for (char c: s) ct[c]++;
    long long max = ct[c], min = ct[c];
    for (pair<char,long long> p: ct) {
        max = fmax(max, p.second);
        min = fmin(min,p.second);
    }
    cout << max-min << " " << max << " " << min <<endl;
    // new things never interact with other kids in the neighborhood
}*/