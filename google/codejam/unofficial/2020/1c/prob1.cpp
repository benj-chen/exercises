// looked at solution
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define f first
#define s second
int manhattan_dist(pii p) {
    return (p.f>0? p.f: -p.f) + (p.s>0? p.s: -p.s);
}
bool pii_compare(pii a,pii b) {
    return manhattan_dist(a)<manhattan_dist(b);
}
string m;
int x,y,mlen;
int c,d; // current position
// 0 <= (x,y) TO BEGIN WITH
// m<=1000, can use vector to hold all the points
pii pos[1000];
pii sorted_pos[1000];
void getpos_s() {
    pos[0]=make_pair(x,y);
    sorted_pos[0]=pos[0];
    for (int i=0;i<mlen;i++) {
        pos[i+1]=make_pair(pos[i].f+(m[i]=='E'? 1: (m[i]=='W'? -1:0)), pos[i].s+(m[i]=='N'? 1: (m[i]=='S'? -1:0)));
        sorted_pos[i+1]=pos[i+1];
    }
    sort(sorted_pos,sorted_pos+mlen,pii_compare);
}

bool impossible() {

    return 0;
}
void solve() {

    int sol=0;
    if (impossible()) {
        cout << "IMPOSSIBLE\n";
        return;
    }

}
int main() {
    int T;
    cin >> T;
    T++;
    for (int t=1;t<T;t++) {
        cin >> x >> y >> m;
        cout << "Case #" << t << ": ";
        mlen=m.length();
        solve();
    }
    // just solve test set 1 for now
}