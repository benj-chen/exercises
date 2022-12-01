#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<deque>
#include<array>
#define f(n) for (int i=0;i<n;i++)
#define ff(i,n) for (int i=0;i<n;i++)
#define fff(i,m,n) for (int i=m;i<n;i++)
using namespace std;
using vi = vector<int>;
using ll = long long;
int n,res;
bool notyet(vector<array<int,3>>& i) {
	for (auto j: i) {
		if (j[0]==n) {res = j[2];return true;}}return false;
}
int main(){int T;cin>>T;ff(t,T){
	int pr=1; cin >> n;
	cout << "ok" << endl;
	vector<array<int,3>> vals ={ {1,0,1}}; // num, stored_value
	while (!notyet(vals)) {	
	// for (int j=0;j<n;j++) {
		int q = vals.size();
		f(q) {
			// +6
			vals.push_back({vals[i][0],vals[i][0]*2,vals[i][2]+6});

			// double
			if (vals[i][1])
			vals.push_back({vals[i][0]+vals[i][1],vals[i][1],vals[i][2]+2});

			// add 1
			vals.push_back({vals[i][0]+1,vals[i][1],vals[i][2]+1});
			
		}
		cout << vals.size() << endl;
	}
	int min = 1e9;
	for (auto i: vals) {
		if (i[0]==n) min = fmin(i[2],min);
	}
	cout << "Case #" << t+1 << ": " << min << endl;

}}
