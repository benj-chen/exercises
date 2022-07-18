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

struct rect {
    int a,b,c,d; // a,b, is top left, c,d is bottom right
    rect(int a,int b,int c,int d) {
        this->a=a;
        this->b=b;
        this->c=a+c;
        this->d=b+d;
    }
    bool overlaps(const rect& r) {
        return((
            a < r.a && r.a<=c || 
            a < r.c && r.c<=c) &&
            (b < r.b && r.b<=d || 
            b < r.d && r.d<=d)
        );
    }
};
int main() {
    string s;
    int a,b,c,d,id;
    char g;
    vector<rect> v; // first is empty
    while (cin>>g >> id) {
        cin >> s;
        cin >> a;
        cin.ignore();
        cin>>b;
        cin.ignore();
        cin >> c;
        cin.ignore();
        cin >> d;
        // round robin comparison
        v.push_back(rect(a,b,c,d));
    }
    int ct;
    for (int i=0;i<v.size();i++) {
        ct=0;
        for (int j=0;j<v.size();j++) {
        if (v[i].overlaps(v[j]) || v[j].overlaps(v[i])) {
            ct++;
        }
    }
    if (ct==0) {
            cout << i +1<< "!" << endl;
        }
    }
}
