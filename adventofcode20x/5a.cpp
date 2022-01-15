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

bool type(char c) {
    return ('A'<=c && c<='Z');
}
char tolower(char c) {
    if (type(c)) return c-'A'+'a';
    return c;
}
int main() {
    string s;
    cin >> s;
    for (int i=0;i<s.size()-1;i++) {
        if (type(s[i])!=type(s[i+1]))
        {
            if (tolower(s[i])==tolower(s[i+1]))
            {
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
                i-=2;
            }
        }
    }
    cout << s.size() << endl;
}