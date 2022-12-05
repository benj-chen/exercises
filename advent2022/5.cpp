#include<iostream>
#include<cmath>
#include<vector>
#include<deque>
using namespace std;
vector<string> split_delimiter_char(string s, char delim) {
    vector<string> res(1);
    for (char c: s) {
        if (c==delim) res.push_back("");
        else res.back()+=c;
    }
    return res;
}
int main() {
	string s;
	vector<deque<char>> crates;
	bool first_time = 1;
	while (getline(cin,s)) {
		if (s == "") break;
		cout << "'" << s << "'" << endl;
		// process 4 chars at a time. note that there is no trailing space
		if (first_time) crates.resize((s.size()+1)/4);
		
		for (int i=0;i<s.size();i+=4) {
			if (s[i]=='[') {
				crates[i/4].push_back(s[i+1]);
			}
		}
		first_time = 0;
	}
	cout << "ok" << endl;
	// process queries
	while (getline(cin,s)) {
		auto v = split_delimiter_char(s,' ');
		int n = stoi(v[1]), fr = stoi(v[3]), to = stoi(v[5]);
		cout << n << fr << to << endl;
		for (int i=0;i<n;i++) {
			crates[to-1].push_front(crates[fr-1].front());
			crates[fr-1].pop_front();
		}
	for (deque<char> d: crates) {
		cout << d.front();
	}
	}
	cout << endl;
}
