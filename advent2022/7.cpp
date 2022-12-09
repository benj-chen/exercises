#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;

vector<string> split(string s, char delim) {
    vector<string> res(1);
    for (char c: s) {
        if (c==delim) res.push_back("");
        else res.back()+=c;
    }
    return res;
}
string find_path(stack<string> d) {
	if (d.size()==1) return "/";
	string res = "";
	while (d.size()!=1) {
		
		res+=d.top()+"/";
		d.pop();
	}
	return res+"/";
}	
int main() {
	string s;
	stack<string> dirs;
	map<string,long long> sizes;
	dirs.push("/");
	getline(cin,s);
	bool skip = false;
	string path="/";
	while (getline(cin,s)) {
		if (s[0]=='$'){if (s[2]=='c') {
			long long to_add;
			switch(s[5]) {
				case '.':
				// cd .., add filesize previous, pop
				to_add = sizes[path];
				dirs.pop();
				path = find_path(dirs);
				sizes[path]+=to_add;
				break;
				case '/':
				while (dirs.size() > 1) {

					to_add = sizes[path];
					dirs.pop();
					path = find_path(dirs);
					sizes[path]+=to_add;
				}
				break;
				default:
				// cd dir, add dir to stack
				dirs.push(split(s,' ')[2]);
				path = find_path(dirs);
			}
		}	
		if (s[2]=='l') {
			// dir can't already have a value
			if (sizes[path]) {
				skip = true;
			}
		}
		}
		else {
			// ls item
			if (!skip)if (s[0]!='d') sizes[path]+=stoi(split(s,' ')[0]);
		}
	}
	while (dirs.size() > 1) {
		long long to_add = sizes[path];
					dirs.pop();
					path = find_path(dirs);
					sizes[path]+=to_add;
	}
	long long total = 0;
	for (auto i: sizes) {
		if (i.second<=100000){total+=i.second;}
	}
	cout << total<< endl;
	long long to_remove = sizes["/"]-40000000;
	int min = 1e9;
	for (auto i: sizes) if (i.second < min and i.second > to_remove) min = i.second;
	cout << min << endl;
} 
