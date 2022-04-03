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
    vvi v;
    string c;
    while (cin>>c) {
        v.push_back(vector<int>());
        for (char cc: c) {
            v.back().push_back(cc-'0');
        }
    }
    for (int i=v.size()-1;i>0;i--) {
        for (int j=v[0].size()-1;j>0;j--) {
            for (int k=-1;k<1;k++) {
                for (int l=-1;l<1;l++) {
                    if (k!=l) {
                        v[i+k][j+l]+=v[i][j];
                    }
                }
            }
        }
    }
    for (vi vv: v) {
        for (int i: vv) {
            cout << i << "\t";
        }
        cout << endl;
    }
}