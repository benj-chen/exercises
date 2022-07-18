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

struct order {
    string datetime;
    int cmd;
    order(string date, string time, string cmd): datetime(date+time) {
        this->cmd = (cmd[0]=='#'? stoi(cmd.substr(1)): -1);
    }
};
int main() {
    vector<pair<string,int>> orders;
    string date,string time, string cmd;
    while (cin>>date>>time>>cmd>>cmd) {
        int a;
        if (cmd[0]=='#') {
            a=stoi(cmd.substr(1));
        }
        else {
            if (cmd=="up") {
                a=0;
            }
            else a=-1; // asleep
        }
        orders.push_back(make_pair(date+time,a));
        getline(cin,date);//prep for next
    }
    sort(all(orders));
    map<int,int> sleeptime;
    for (pair<string,int> p: orders) {
        if (p.second>10) {
            
        }
    }
}