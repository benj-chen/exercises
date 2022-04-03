// c
#include <bits/stdc++.h>
using namespace std;
map<int,string> base {
		{'O'+'W',"C"},
		{'W'+'C',"O"},
		{'C'+'O',"W"},
		{'O'+'O',""},
		{'W'+'W',""},
		{'C'+'C',""}
};
vector<string> v;
string reduce(string in) {
	if(in.size() <2) return in;
	if (in.size()==2) {
		//cout << in << ":"<<base[in[0]+in[1]] << endl;
		return base[in[0]+in[1]];
	}
	if (in.size()%2) {
		// odd
		string a = reduce(string(1,in[0])+ reduce(in.substr(1))),
		       b = reduce(reduce(in.substr(0,in.size()-1) )+ string(1,in.back()));
		//cout << "a is "<< a << " b is " << b << endl;
		//cout << "a originally was " << string(1,in[0]) << " and "<< (in.substr(1)) << " b was " << in.substr(0,in.size()-1) << " and " << string(1,in.back()) << endl;
		return b;
	}
	else {
	
		// even
		string res;
		for (int i=0;i<in.size();i+=2) {
			res+= base[in[i]+in[i+1]];
		}
		//cout <<in << ":" << res << "\t";
		res = reduce(res);
		//cout <<in << ":" << res << endl;
		return res;
	}
}
int main() {
	// any 2 letter set can either be reduced to nothing or the letter that is not in the set
	string s; cin >> s;
	int q;
	cin >> q;
	while (q--) {
		int a,b;
		cin >> a >> b;
		a--; b--;
		string res = reduce(s.substr(a,b-a+1));
		cout << (res == "C" ? 'Y':'N');
	}
	cout << endl;
}


