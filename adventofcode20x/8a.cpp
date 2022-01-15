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
long long ct=0;
vi v;
void ign(int i) {

    int k;
    for (int j=0;j<i;j++) {
        cin>>k;
    }
}
int process(int st) {
    cout << v[st] << endl;
    int meta = v[st+1];

    ct+=v[st+1];
    if (v[st]==0) {
        F(i,v[st+1]) {
            ct+=v[st+2+i];
        }
        return st+v[st+1]+1;
    }
    int prev=st+1;
    F(i,v[st]) {
        cout<<"x";
        prev = process(prev+1);
    }
    FO(i,)
    return prev+v[st+1]+1;
}

int main() {
    int i;
    while (cin>>i) v.push_back(i);
    process(0);
    cout << ct << endl;
}