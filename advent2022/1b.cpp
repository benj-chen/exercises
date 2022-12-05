#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	string s;
	int cur = 0;
	vector<int> all;

	while (getline(cin,s)) {
		if (s=="") {
			all.push_back(cur);
			cur = 0;
		}
		else {
			cur += stoi(s);
		}
	}

	sort(all.begin(),all.end());
	int total = 0;
	for (int i=all.size()-3;i<all.size();i++) {
		total += all[i];
	}

	cout << total << endl;
}
