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

struct box {
    int x1, x2, y1, y2,z1,z2; // top left, bottom right
    array<int,3> recent_ol_pt; // most recent overlap point
    box(int x1, int x2, int y1, int y2,int z1,int z2): x1(fmin(x1,x2)), x2(fmax(x1,x2)), y1(fmin(y1,y2)), y2(fmax(y2,y1)), z1(fmin(z1,z2)),z2(fmax(z1,z2)) {}
    boxl overlap(const box& other) {
        // does it partly overlap?
        return
        ((x1 <= other.x1 && other.x1 <= x2) ||
        (x1 <= other.x2 && other.x2 <= x2) ||) &&
        ((y1 <= other.y1 && other.y1 <= y2) ||
        (y1 <= other.y2 && other.y2 <= y2) ||) &&
        ((z1 <= other.z1 && other.z1 <= z2) ||
        (z1 <= other.z2 && other.y2 <= z2))
        ;
    }
    bool in(const box& other) {
        // is this completely in the other box?
        return other.x1 <= x1 && other.x2 >= x2 && other.y1 <= y1 && other.y2 >= y2 && other.z1 <= z1 && other.z2 >= z2;
    }
    bool covers(const box& other) {
        // does this completely encapsulate the other box?
        return x1<=other.x1 && x2>=other.x2 && y1<=other.y1 && y2>=other.y2 && z1 <= other.z1 && z2 >= other.z2;
    }
};

int main() {
    string onoff;
    vector<pair<pair<int,int>, pair<int,int>>> boxes;
    while (cin>>onoff) {
        int x1,x2,y1,y2,z1,z2;
        cin.ignore(3);
        cin >> x1;
        cin.ignore(2);
        cin >> x2;
        cin.ignore(3);

        cin >> y1;
        cin.ignore(2);

        cin >> y2;
        cin.ignore(3);
        cin >> z1;
        cin.ignore(2);
        cin>>z2;
        if (x1>x2) {
            x1+=x2;
            x2 = x1-x2;
            x1-=x2;
        }
        if (y1>y2) {
            y1+=y2;
            y2 = y1-y2;
            y1-=y2;
        }
        if (z1>z2) {
            z1+=z2;
            z2 = z1-z2;
            z1-=z2;
        }
        if (onoff=="on") {
        }
    }
}