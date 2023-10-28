// https://codeforces.com/problemset/problem/1864/Do


#include<iostream>
#include<vector>
using namespace std;
/*
struct node {
node*  lc;
node* mc;
node* rc; // each node has 3 children
bool state; //to_prop = false; // to propagate flips or not
node(bool state): state(state) {}
};
*/
int main() {int t; cin >> t; for (int T=0;T<t;T++) {
	/*
	// nodes and keep track of heads
	int n, total = 0; cin>> n;
	char c;
	node nodes[n][n];
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		cin >> c;
		nodes[i][j] = node(c=='1'); // forgot how to initialize lol
	}
	for (int i=0;i<n-1;i++) {
		// set children
		for (int j=0;j<n;j++) {
			if (j>0) nodes[i][j]->lc =  nodes[i+1][j-1];
			if (j+2 > n) nodes[i][j]->rc = nodes[i+1][j+1];
			nodes[i][j]->mc = nodes[i+1][j];
		}
	}

	// run through
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (nodes[i][j].state){
		// prop
		total++;
		if (nodes[i][j]->lc) nodes[i][j]->lc.state = not nodes[i][j]->lc.state;
		if (nodes[i][j]->mc) nodes[i][j]->mc.state = not nodes[i][j]->mc.state;
		if (nodes[i][j]->rc) nodes[i][j]->rc.state = not nodes[i][j]->rc.state;
	}	
	cout << total << endl;
	*/
	// start up and simulate down
	int n; cin>>n;
	char ar[n][n];
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {cin >> ar[i][j];ar[i][j]-='0';}

	// is this fast enough?
	int num_ops = 0;
	for (int cur_row = 0;cur_row<n;cur_row++){
		for (int i=0;i<n;i++) if (ar[cur_row][i]) {
			// do flip
			num_ops++;
			// only flip next row
			if (i>0) ar[cur_row+1][i-1] = !ar[cur_row+1][i-1];
			if (i+1 < n) ar[cur_row+1][i+1] = !ar[cur_row+1][i+1];
			ar[cur_row+1][i]=!ar[cur_row+1][i];
		}
	}
	cout << num_ops << endl;
}
}
