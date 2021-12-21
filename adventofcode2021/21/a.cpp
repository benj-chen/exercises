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

int sumrange(int st, int end) {
    assert (end>=st);
    return (st+end)*(end-st+1)>>1;
}
int main() {
    cout<<sumrange(1,3)<<endl;
    int p1, p2;
    string garbage;
    cin >> garbage >> garbage >> garbage >> garbage >> p1;
    cin >> garbage >> garbage >> garbage >> garbage >> p2;
    int times=0;
    bool turn = 1; // p1 first
    int score1=0, score2=0;

    while (score1<1000 && score2<1000) {
        if (turn) {
            p1 += sumrange((times)*3+1,(times+1)*3);
            score1+=p1%10+(10*!(p1%10));
            cout<<p1<<" "<<score1<<endl;
        }
        else {
            p2 += sumrange((times)*3+1,(times+1)*3);
            score2+=p2%10+(10*!(p2%10));
            cout<<p2<<" "<<score2<<endl;
        }
        turn= !turn;
        times++;
    }
    cout<<score1<<" " <<score2 << " " <<times << endl;
    if (score1<1000) {
        cout << score1*times*3 << endl;
    }
    else cout <<score2*3*times<<endl;
}