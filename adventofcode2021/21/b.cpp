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
    int p1, p2;
    string garbage;
    cin >> garbage >> garbage >> garbage >> garbage >> p1;
    cin >> garbage >> garbage >> garbage >> garbage >> p2;
    // result is always 1+1+1, 1+1+2... 3+3+3
    // may have to multiply end result by 3 because of double cases (triple?) ie 1+2+1 = 1+1+2 = 2+1+1
    // not for all: 1+1+1 has only one case, 1+2+3 has 6

    // for each person, for each amount of moves, how many PUs are there to achieve this? then just add them up
    // max moves roughly: 14 (21/(1+2)*2); min 21/17*2 = 3
}