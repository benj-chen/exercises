#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<deque>
#define f(n) for (int i=0;i<n;i++)
#define ff(i,n) for (int i=0;i<n;i++)
#define fff(i,m,n) for (int i=m;i<n;i++)
using namespace std;
using vi = vector<int>;
using ll = long long;
// every node has a list of scoring values, each is the "score if I was approaching from this node". Includes the self node.
// to calculate the final result for a node, take all working sums
// vi sums;
vector<map<int,int>> scores;
int dfs(vector<vi>& g, const vi& values, int parent, int current) {
	
	if (values[current]>=values[parent])return 0;
	if (scores[current][parent]) return scores[current][parent];
	int res = 1;
	for (int i: g[current]) if (i!=parent) {
		res += dfs(g,values,current,i);
	}
	// sums[current]+=res-1;
	scores[current][parent] = res;
	return res;
}
int main(){int T;cin>>T;T++;fff(t,1,T){
	int n; cin >> n;
	vi a(n+1); f(n) cin >> a[i+1];
	a[0]=2e9;
	vector<vi> g(n+1);
	scores.clear();
	scores.resize(n+1);
	// sums.clear();sums.resize(n);
	f(n-1) {
		int x,y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int max = 0;
	f(n) {
		cout << dfs(g,a,0,i+1) << endl;
		max = fmax(max,dfs(g,a,0,i+1));
	}
	cout << "Case #" << t << ": " << max << endl;

}}
