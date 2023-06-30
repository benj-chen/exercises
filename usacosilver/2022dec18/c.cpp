// post comp for fun
#include<assert.h>
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int>> v;
	for (int i=0;i<n;i++) {
		vector<int> t(n-i);
		for (int j=i;j<n;j++) {
			cin >> t[j-i];
		}
		v.push_back(t);
	}
	if (n==1) {
		cout << 0 << endl;
		return 0;
	}
	deque<int> sol {v[n-2][0],v[n-2][1]};
	for (int i=n-3;i>-1;--i) {
		// consider v[i] as a list
		deque<int> cp1(sol), cp2(sol);
		cp1.push_front(cp1.front() + v[i][1]);// possible next lists
		cp2.push_front(cp2.front() - v[i][1]);
		// does it work?

		auto works = [&](deque<int>& cp) {
			vector<int> ans;
			int max=cp[0],min=cp[0];
			for (int item: cp) {
				if (item<min) min = item;
				if (item>max) max = item;
				ans.push_back(max-min);
			}
			assert(ans.size()==v[i].size());
			for (int index = 0;index<ans.size();index++) {
				if (ans[index] != v[i][index]) {
					return false;
				}
			}
			return true;
		};
		if (works(cp1)) {
			sol.push_front(sol.front()+v[i][1]);
		}
		else if (works(cp2)) {
			sol.push_front(sol.front()-v[i][1]);
		}
		else {
			cout << "Error: neither worked" << endl;
			for (auto j: v[i]) cout << j << " ";
			cout << endl;
			for (auto j: sol) cout << j << " ";
			cout << endl;
		}
	}
	cout << sol[0];
	for (int i=1;i<n;i++) {
		cout <<" "<<sol[i];
	}
	cout << endl;
}
