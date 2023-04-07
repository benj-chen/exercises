#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#define f(n) for (int i=0;i<n;i++)
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vv = vector<vi>;
using si = set<ll>;
using vs = vector<si>;
vv graph;
vi values;
int n;
ll sum;
vv res1;
stack<vi> res2;
//si leaf;
queue<int> leaf;

void rm(vi& s, ll to_remove) {
	auto i = find(s.begin(),s.end(),to_remove);
	if (i!=s.end()) {
		s.erase(i);
	}
}
void solve2() {
	// push and pull
	while (!leaf.empty()) {
		if (values[leaf.front()]>0) {
			res1.push_back({leaf.front(),leaf.front()+1,graph[leaf.front()][0]+1,values[leaf.front()]});
		}
		else if (values[leaf.front()]==0) {} else{
			// never 0
			res2.push({leaf.front(),graph[leaf.front()][0]+1,leaf.front()+1,-values[leaf.front()]});
		}
		if (graph[leaf.front()].size()==1 and graph[graph[leaf.front()][0]].size()==1) {
			return;
		}
		rm(graph[graph[leaf.front()][0]],leaf.front());
		values[graph[leaf.front()][0]]+=values[leaf.front()];
		values[leaf.front()]=0;
		leaf.pop();
		leaf.push(graph[leaf.front()][0]);
	}

}
/*
void solve() {
	for (ll i: values) if (i) goto start;
	return;
start:;
	// push and pull
	for (ll i: leaf) {
		rm(graph[graph[i][0]],i);
		if (values[i]>0) {
			res1.push_back({i+1,graph[i][0]+1,values[i]});
		}
		else if (values[i]==0) continue; else{
			// never 0
			res2.push({graph[i][0]+1,i+1,-values[i]});
		}
		values[graph[i][0]]+=values[i];
		values[i]=0;
	}
	leaf.clear();
	// find leaf nodes
	f(n) {
		if (graph[i].size()==1) {
			if (values[i])
				leaf.insert(i);
			else
				// remove from parent
				rm(graph[graph[i][0]],i);
		}
	}
	for (ll i: leaf) {
		cout << i << " ";
	}
	cout << endl;
	for (ll i: values) cout << i << " "; cout << endl;
	for (ll j: leaf){
		f(graph[graph[i][0]].size()) cout << graph[graph[j][0]][i] << " "; cout << endl;}
	solve();
}
*/

int main() {
	cin >> n;
	graph.resize(n);
	values.resize(n);
	sum = 0;
	f(n) {cin >> values[i]; sum += values[i];}
	sum /= n;
	for (ll& i: values)
		i -= sum;
	//for (ll i: values) cout << i << " "; cout << endl;
	f(n-1) {
		int a,b; cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	// find leaf nodes
	f(n) {
		if (graph[i].size()==1) {
			if (values[i])
				leaf.push(i);
			else
				// remove from parent
				rm(graph[graph[i][0]],i);
		}
	}
	//cout << "solve prep done" << endl;
	
	solve2();
	cout << res1.size() + res2.size() << endl;
	for (vi v: res1) {
		f(v.size()-1) cout << v[i] << " ";
		cout << v.back() << endl;
	}
	while (res2.size()!=0) {
		f(res2.top().size()-1) cout << res2.top()[i] << " ";
		cout << res2.top().back() << endl;
		res2.pop();
	}
	//cout << "end" << endl;
}
