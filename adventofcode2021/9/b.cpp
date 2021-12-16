#include <iostream>
#include <vector>
#include <utility> // pair
#include <queue>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pib = pair<int,bool>;
using pii = pair<int,int>;
using vp = vector<pib>;
vector<vp> graph;
int sz = 0;
void dfs(int x, int y) {
    if (x>=graph.size() || x<0 || y>=graph[0].size() || y<0) return;
    if (graph[x][y].first==9 || graph[x][y].second) return;
    sz++;
    graph[x][y].second = 1;
    for (int i=-1;i<2;i++) for (int j=-1;j<2;j++) if (i==0 || j==0)
        dfs(x+i,y+j);
}
vector<pii> low_pt() {
    vector<pii> res;
    for (int i=0;i<graph.size();i++) for (int j=0;j<graph[0].size();j++) {
        bool low = 0;
        int k_st = -1, k_end = 2, l_st = -1, l_end = 2;
        
        if (!i) k_st = 0;
        else if (i==graph.size()-1) k_end = 1;

        if (!j) l_st = 0;
        else if (j==graph[0].size()-1) l_end = 1;
        
        for (int k=k_st;k<k_end;k++) for (int l=l_st;l<l_end;l++)
            if ((k!=0 || l!=0) && graph[i+k][j+l].first <= graph[i][j].first) low=1;
        
        if (!low) res.push_back(make_pair(i,j));
    }
    return res;
}
int main() {
    string s;
    while(cin>>s) {
        graph.push_back({});
        for (char c:s) graph.back().push_back(make_pair(c-'0',0));
    }
    priority_queue<int> sizes;
    for (pii p: low_pt()) {
        dfs(p.first, p.second);
        sizes.push(sz);
        sz=0;
    }
    int res = 1;
    for (int i=0;i<3;i++) {
        res *= sizes.top();
        sizes.pop();
    }
    cout<<res<<endl;
}