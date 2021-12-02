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

void solve() {
    string s;
    cin>>s;
    int sz = s.size();
    // if one letter takes up more than half then impossible
    map<char,int> appear;
    for (char c: s) {
        appear[c]++;
    }
    for (pair<char,int> p: appear) if (p.second > (sz>>1)) {
        cout << "IMPOSSIBLE" << endl; return;
    }
    string cp = s;
    map<int,bool> done; // int is index
    F(i,sz) {
        if (cp[i]!=cp[sz-1]) {
            cout<<cp[sz-1]<<cp[i]<<endl;
            cp[sz-1]+=cp[i];
            cp[i]=cp[sz-1]-cp[i];
            cp[sz-1]-=cp[i];
            done[i]=1;
            done[sz-1]=1;
            cout<<cp[sz-1]<<cp[i]<<endl;
            

            break;
        }
    }
    cout << cp << " "<< s << endl;
    // mark
    for (int i=0;i<sz-1;i++) {
        if (!done[i]) {
            for (int j=0;j<sz;j++) {
                if (!done[j] && cp[j]!=cp[i]) {
                    cp[j]+=cp[i];
                    cp[i]=cp[j]-cp[i];
                    cp[j]-=cp[i];
                    done[i]=1;
                    done[j]=1;
                    break;
                }
            }
        }
    }
    cout<<cp<<endl;
    return;
    // reverse(all(s));
    for (int i=0;i<sz;i++) {
            for (int j=i+1;j<sz;j++) {
                if (cp[j]!=cp[i]) {
                    cp[j]+=cp[i];
                    cp[i]=cp[j]-cp[i];
                    cp[j]-=cp[i];
                    break;
                }
            }
    }
    cout << cp << endl;
    return;
    // swap last with different one
    for (char& c: s) {
        if (c!=s.back()) {
            s.back() += c;
            c = s.back() - c;
            s.back() -= c;
            break;
        }
    }
    cout<<s<<" " << cp << endl;
    for (char c: cp) {
        F(i,s.size()) {
            if (c!=s[i]) {
                cout << s[i];
                s = s.substr(0,i) + s.substr(i+1);
                break;
            }
        }
    }
    cout << s << endl;
}

int main() {
    int T;
    cin >> T;
    T++;
    FO(t,1,T) {
        cout << "Case #" << t << ": ";
        solve();
    }
}