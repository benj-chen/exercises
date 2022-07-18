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

int main() {
    string s;
    int ct2=0, ct3=0;
    while (cin>>s) {
        sort(all(s));
        char prev = ' ';
        int ct = 0;
        bool two=0,three=0;
        for (char c: s) {
            if (c!=prev) {
                if (ct==2) {
                    two=1;
                }
                if (ct==3) {
                    three=1;
                }
                ct=0;
            }
            ct++;
            prev=c;
        }    if (ct==2) {
                    two=1;
                }
                if (ct==3) {
                    three=1;
                }
        if (two) ct2++;
        if (three) ct3++;
        cout << two << three << endl;
    }
    cout << ct2 << " " << ct3 << " " << ct2*ct3 << endl;
}
// 4940 low