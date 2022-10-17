
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
vector<int> layer_cap;
void dfs(int from,int src, int depth) {
    layer_cap[depth]++;
    for (int i: tree[src]) {
        if (i != from)
        dfs(src,i,depth+1);
    }
}
int main(){
int T;cin>>T;T++;for(int t=1;t<T;t++) {
    int n,q; cin >> n >> q;
    tree.clear();
    layer_cap.clear();
    tree.resize(n);
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        tree[a-1].push_back(b-1); // zero index
        tree[b-1].push_back(a-1); // zero index

    }
    // take in q
    for (int i=0;i<q;i++) {
        int e; cin >> e;
    }
    // do bfs, calc capacity per layer
    // or dfs may be easier honestly
    layer_cap.resize(n+1);
    dfs(0,0,0);
    int origq = q;
    int total = 0;
    for (int i: layer_cap) {
        if (q-i <0) break;
        q -= i;
        total+=i;
    }
    // cout << endl;
    // for (int i: layer_cap) cout <<"ee" << i << endl;
    // number of queries left == number of partially filled
    cout << "Case #" << t << ": " << total << endl;
}
}