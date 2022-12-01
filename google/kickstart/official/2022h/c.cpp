#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<deque>
#include<utility>
#define f(n) for (int i=0;i<n;i++)
#define ff(i,n) for (int i=0;i<n;i++)
#define fff(i,m,n) for (int i=m;i<n;i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
vector<vi> graph;
vi caps;
struct Node {
	map<int,int> value;// from node, value flowing to the from node
	int i, cap,selfvalue= -1;
	Node(int i): i(i){
		for (int j: graph[i]) {
			value[j] = -1;
		}
	}
	int g_value(int from, vector<Node>& ngraph) {
		
		if(value[from]!=-1) return value[from];
		value[from] = 1;
		for (int j: graph[i]) if (j!=from) {
			if (caps[i] > caps[j]) value[from] += ngraph[j].g_value(i, ngraph);
		}
		
		return value[from];
	}
};
vector<Node> ngraph;
// vi values;
// int get_values(int at, int from) {
	// if (graph[at]!=-1) return graph[at];
	// int it = 1;
	// for (int i: graph[at]) {
		// it += get_values(i,at);
	// }
	// graph[at].second = it;
	// return it;
// }
int main(){int T;cin>>T;ff(t,T){
	int n; cin >> n;
	caps.clear();
	caps.resize(n);
	ngraph.clear();
	graph.clear();
	graph.resize(n);
	f(n) {
		cin >> caps[i];
	}
	f(n-1) {
		int j,k; cin >>j  >> k;
		j--;k--;
		// cout << "e";
		graph[j].push_back(k);

		graph[k].push_back(j);
	}
	// f(n) {
		// for (auto j: graph[i]) cout << j << " "; cout << endl;}
	f(n) {
		ngraph.push_back(Node(i));}
	f(n) {
		//if (graph[i].size()==1) {
		for (int j: graph[i]) {
			ngraph[j].g_value(i,ngraph);
			ngraph[i].g_value(j,ngraph);
		}
		if (false) {
			// cout<<"YEP"<<endl;
			ngraph[graph[i][0]].g_value(i,ngraph);
			if (caps[i]>caps[graph[i][0]]) ngraph[i]= ngraph[graph[i][0]].value[i]+1;
		}
	}
	// biggest sum
	//vi q(n);
	int max = 0;
	f(n) {
		// for (auto j: ngraph[i].value) {
			// if (j.second!=-1)q[j.first]+=j.second;}
		int s = 0;
		for (auto j: ngraph[i].value) {
			if(j.second!=-1) s+=j.second;
		}
		max = fmax(max,s);
		//cout << s << endl;
	}
	// for (int i: q) {
		// cout << i << endl;
		// max=fmax(i,max);
	// }

	cout << "Case #" << t+1 << ": " << max+1 << endl;

}}

