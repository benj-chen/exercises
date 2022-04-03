// b
#include <bits/stdc++.h>
#define vt vector
using namespace std;
char yn(bool b) {
	return (b? 'Y':'N');
int main() {
	string s,t; cin >> s >> t;
	map<char,vt<int>> ms,mt;
	for (char c: s) ms[c]++;
	for (char c: t) mt[c]++;
	int q; cin >> q; 
	while (q--) {
		string a; cin >> a;
		if (a.size()==1) {
			cout << yn(ms[a[0]].size() == mt[a[0]].size());
		}

	}
}
