// post comp for fun
#include<assert.h>
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int>> v;
	// get inputs just as described, even though we don't use the 0's. Probably a cleaner way to collect input but simple is good
	for (int i=0;i<n;i++) {
		vector<int> t(n-i);
		for (int j=i;j<n;j++) {
			cin >> t[j-i];
		}
		v.push_back(t);
	}
	if (n==1) {
		cout << 0 << endl; // any number will do
		return 0;
	}
	deque<int> sol {v[n-2][0],v[n-2][1]}; // this is why we need to make the special exception for n=1
	for (int i=n-3;i>-1;--i) {
		// consider v[i] as a list
		deque<int> cp1(sol), cp2(sol);
		cp1.push_front(cp1.front() + v[i][1]);// possible next lists based on the difference between the first element and the new element to consider
		cp2.push_front(cp2.front() - v[i][1]); // is this new element greater or less than the first element by v[i][1]? try both!
		// does it work?
		auto works = [&](deque<int>& cp) {
			vector<int> ans;
			int max=cp[0],min=cp[0];
			for (int item: cp) { // construct the current row of differences that we're working on based on this tentative new element
				if (item<min) min = item;
				if (item>max) max = item;
				ans.push_back(max-min);
			}
			assert(ans.size()==v[i].size()); // sanity check
			for (int index = 0;index<ans.size();index++) { // check against the actual row
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
		else { // thankfully this is never called :)
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
