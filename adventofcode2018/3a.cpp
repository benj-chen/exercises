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
    int a,b,c,d;
    int ct[1000][1000] = {};
    while (cin>>s) {
        cin >> s;
        cin >> a;
        cin.ignore();
        cin>>b;
        cin.ignore();
        cin >> c;
        cin.ignore();
        cin >> d;
        for (int i=b;i<b+d;i++) {
            for (int j=a;j<a+c;j++) {
                ct[i][j]++;
            }
        }
    }
    int totals=0;
    for (int i=0;i<1000;i++) {
        for (int j=0;j<1000;j++) {
            if (ct[i][j]>1) totals++;
        }
    }
    cout << totals << endl;
}