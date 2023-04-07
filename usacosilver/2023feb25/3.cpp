#include<iostream>
#include<utility>
#include<vector>
#include<assert.h>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
#include<cmath>

#define f3(v,st,sp,se) for (int v=st;v<sp;v+=se)
#define f2(v,st,sp) for (int v=st;v<sp;v++)
#define f1(v,sp) for (int v=0;v<sp;v++)
#define f(sp) for (int i=0;i<sp;i++)

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using p = pair<int,int>;
int main() {
	int n,m;
	cin >> n >> m;
	vector<vvi> g(n); //dest, time that it leaves, time that it arrives
	int temp_ar[4][m+1];
	int layover[n];
	f(m) {
		cin >> temp_ar[i][0]>> temp_ar[i][2]>> temp_ar[i][1]>> temp_ar[i][3];
	}
	f(n) {
		cin >> layover[i];
	}
	f(m) {
		g[temp_ar[i][0]-1].push_back({temp_ar[i][1]-1,temp_ar[i][2],temp_ar[i][3]+layover[temp_ar[i][1]-1]});
	}
	// bfs
	queue<p> q;
	q.push({0,0});
	int mins[n];
	f(n) mins[i]=1e9+1;
	while (!q.empty()) {
		// look at all possible flights
		int a = q.front().first, b = q.front().second;
		q.pop();
		mins[a] = fmin(mins[a],b-layover[a]);
		//cout << a << " " << b <<endl;;
		f(g[a].size()) {
			//cout << g[a][i][1] << endl;
			if (g[a][i][1] >= b) {
				q.push({g[a][i][0],g[a][i][2]});

				g[a].erase(g[a].begin()+i);
			i--;
			}
		}
		/*
		for (vi v: g[a]) { // for each outgoing flight

			// is it possible?
			else if (v[1] >= b) {
				q.push({v[0],v[2]});
			}
			cout << v[0] <<" " << v[1] <<" " << v[2] << endl;
			
		}
		*/
		//cout << endl << endl;
	}
	mins[0]=0;
	f(n){
		if (mins[i]==1e9+1) cout << -1 << endl;
		else cout << mins[i] << endl;
	}
}
