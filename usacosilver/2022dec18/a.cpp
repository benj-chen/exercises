#include<vector>
#include<cmath>
#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<queue>

#define f(n) for (int i=0;i<n;i++)
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vv = vector<vi>;
unordered_set<int> l, // which nodes are leaf nodes
		      // try with normal set also
		   d; // dead ex-leaf nodes with 0 value = solved

vv graph;  // undirected adj list
vi values; // how many extra bales / needed bales are at each node
vv res; // each vector has 3 numbers
queue<vi> res2;
int n;
ll sum;
vv leaf_paths; // for each i, have a vector that shows the path to the nearest leaf

bool is_leaf(int node) {
		return l.count(node); // maybe change later to a pure check of if only one value needs push/pull
}
bool is_alive(int node) {
		return !(d.count(node));
}

void solve() {
	// take next leaves
	for (ll i: values) if (i!=0) goto start;
	return;
start:;
      	
	vv to_manip(n);
      	for (int i: l) {
		cout << i << " ";

		for (int j: graph[i]) {
			if (values[j]) {
				// this is a next leaf
				to_manip[j].push_back(i);
				cout << i << " is a next leaf from " << j << endl;
			}
		}
	}
	cout << endl;
	l.clear();
	// pull from pos, dist to neg, become a leaf
	f(n) {
		if (to_manip[i].size()) {
			
			for (int j: to_manip[i]) {
				if (values[j]>0) {
					res.push_back({j+1,i+1,values[j]});
					values[i]+=values[j];
					values[j]=0;
				}
				
			}
			
			for (int j: to_manip[i]) {
				if (values[j]<0) {
				//*/else {
					// if it can't be done yet, pass to res2 (this will be printed out at the end)
					values[i]+=values[j];
					if (values[i]<0)
						res2.push({i+1,j+1,-values[j]});
					else
						res.push_back({i+1,j+1,-values[j]});
					values[j]=0;
				}
			}
		}
		if (values[i]) l.insert(i);
	}
	solve();
	// insert negative instructions from back if they're not possible
}

void solve2() {
	start:;
	      cout << "q" << endl;
	// check if done
	for (ll i: values) if (i!=0) goto start2;
	// push all + leaf nodes in
	return;
	start2:;
	bool newleaf = false;
	for (int i: l) {
		// push into the one non-dead node
		for (int j: graph[i]) if (values[i]>0) {
			if (is_alive(j)) {
				// cout << "push" << i << j << values[i] << endl;;
				res.push_back({i+1,j+1,values[i]});
				values[j]+=values[i];
				values[i]=0;
				l.erase(l.find(i));
				d.insert(i);
				int unsolved = 0;
				for (int k: graph[j]) {
					if (values[k]) unsolved++;
				}
				if (unsolved==1) {
					l.insert(j);
					newleaf = true;
				}
			}
		}
	}
	if (newleaf) goto start;
	// now we have a tree where all leaves need to pull
	// find most valuable node
	ll highest = 0;
	int c = -1;
	f(n) {
		if (values[i]>highest) {
			highest = values[i];
			c = i;
		}
	}
	// push from C to all leaves
	for (int i: graph[c]) {
		if (is_leaf(i)) {
			// leaf val should be neg
			/*
			if (values[i]>=0) {
				cout << "? leaf val (should be neg) was " << values[i] << endl;
			}
			*/
			res.push_back({c+1,i+1,-values[i]});
			values[c] += values[i];
			values[i] = 0;
			l.erase(l.find(i));
			d.insert(i);
		}
	}
	// make C a leaf
	l.insert(c);
	//solve2();
}

int main() {
	cin >> n;
	graph.resize(n);
	values.resize(n);
	sum = 0;
	f(n) {cin >> values[i]; sum += values[i];}
	sum /= n;
	for (ll& i: values)
		i -= sum;
	for (ll i: values) cout << i << " "; cout << endl;
	f(n-1) {
		int a,b; cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	// find leaf nodes
	f(n) {
		if (graph[i].size()==1) {
			if (values[i])
				l.insert(i);
			else
				d.insert(i);
		}
	}
	cout << "solve prep done" << endl;
	
	solve2();
	cout << res.size() + res2.size() << endl;
	for (vi v: res) {
		f(v.size()-1) cout << v[i] << " ";
		cout << v.back() << endl;
	}
	while (res2.size()!=0) {
		f(res2.front().size()-1) cout << res2.front()[i] << " ";
		cout << res2.front().back() << endl;
	}
	cout << "end" << endl;
}
