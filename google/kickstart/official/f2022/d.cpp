
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main(){
int T;cin>>T;T++;for(int t=1;t<T;t++) {
    int n,k,x,d,m; cin >> n >> k >> x >> d >> m;
    vector<vector<pii>> sched(n);
    for (int i=0;i<m;i++) {
        int pi,li,ri; cin >> pi >> li >> ri;
        sched[pi-1].push_back({li,ri});
    }
    // availability score for each tech lead at each hour: usually 0 or 1, but can be 2 if overlap
    vector<array<int,n>> avail(d);
    for (int i=0;i<d-1;i++) {
        // psums for speed
        for (int j=0;j<n;j++) {
            // check each pair sched[j] to add score
            for (pii p: sched[j]) {
                if (p.first <= i and i <= p.second) {
                    avail[i][j]++;
                }
            }
        }
    }
}
}