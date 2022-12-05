#include<iostream>
#include<vector>
#include<stack>
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
	vector<stack<char>> crates;
	stack<string> cr_build;
	while (getline(cin,s)) {
		if (s == "") break;
		cr_build.push(s);
	}

	crates.resize((cr_build.top().size()+1)/4);
	cr_build.pop(); // 1 2 3...
	while (!cr_build.empty()) {
		// process 4 chars at a time. note that there is no extra
		for (int i=0;i<cr_build.top().size();i+=4) {
			if (cr_build.top()[i]=='[') {
				crates[i/4].push(cr_build.top()[i+1]);
			}
		}
		cr_build.pop();
	}

	// process queries
	while (getline(cin,s)) {
		auto v = split_delimiter_char(s,' ');
		int n = stoi(v[1]), fr = stoi(v[3]), to = stoi(v[5]);
		for (int i=0;i<n;i++) {
			crates[to-1].push(crates[fr-1].top());
			crates[fr-1].pop();
		}
	}

	for (stack<char> d: crates) {
		cout << d.top();
	}
	cout << endl;
}
