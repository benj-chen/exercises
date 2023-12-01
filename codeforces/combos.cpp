#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> gen_combinations_of(vector<int> v) {
	// base case, v.size()==0
	if (v.size()==0) return {{}};
	// inductive step, generate all combinations of everything after v[0]
	int v0 = v[0];
	v.erase(v.begin());
	vector<vector<int>> remaining = gen_combinations_of(v);
	// double the length of remaining by tacking v0 to each element
	int length = remaining.size();
	for (int i=0;i<length;i++) {
		remaining.push_back(remaining[i]);
		remaining[i].push_back(v0);
	}
	// now everything in the first half has v0 in it
	// we've kept combos that don't include v0, too
	return remaining;
}
int main() {
	vector<vector<int>> all_combos = gen_combinations_of({1,2,3,4});
	for (vector<int> combo: all_combos) {
		for (int i: combo) cout << i << " ";
		cout << endl;
	}
}
