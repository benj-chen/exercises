// template for comps
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
// #define iter(c,ind)(ind<0?:(c).end()+ind+1,0)
// #define iter_f(c,ind) ((c).begin()+ind)
// #define iter_b(c,b_ind)((c).end()-b_ind)
// #define iter_b2(c,b_ind)((c).begin()+(c).size()-b_ind)
// ((c).begin()+c.size()-b_ind)
using ll = long long;
using vi = vt<int>;
using vl = vt<ll>;
using vvi = vt<vi>;
using vvl = vt<vl>;
using vvvi = vt<vvi>;
using vvvl = vt<vvl>;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

using vpii = vt<pii>;
using vpll = vt<pll>;

// print vectors with space delimiter because that's more common with comps
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {if(!v.empty())out<<v.front();for(int i=1;i<v.size();i++)out<<' '<<v[i];return out;}

vt<string> upd_strings( vt<string> v) {
    // horiz
    vt<string> res;
    for (auto i: v) {
        int beg_pos = 0;
        F(j,i.size()) {
            if (i[j]=='#') {
                beg_pos = j; break;
            }
        }
        int len = 0;

        while (1) {
            try {
            if (i[beg_pos + ++len] != '#') {
                res.push_back(i.substr(beg_pos+1,len-1));
                beg_pos += len;
                len=0;
            }
            } catch (...) {
                break;
            }
        }
    }
    return res;
}

void solve() {
    int n,m; cin >> n >> m;
    vector<string> v(n);
    F(i,n) {
        cin>>v[i];
    }
    vector<string> prev; // the previous iteration
    vector<string> strings = upd_strings(v);
    cout << strings << endl;
}

int main() {
    int T;
    cin >> T;
    T++;
    F(t,T) {
        cout << "Case #" << t << ": ";
        solve();
    }
}