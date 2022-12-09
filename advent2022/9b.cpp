#include<iostream>
#include<vector>
#include<set>
#define f(n) for (int i=0;i<n;i++)
using namespace std;
pair<int,int>conv(int a, int b) {
	return make_pair(a,b);
        //return ((long long)(a)<<32) + b;
}
int abs(int i) {
	if (i<0) return -i;
	if (i==0) return 1;
	return i;
}
int dir(char c) {
	switch(c) {
		case 'U': return 0;
		case 'R': return 1;
		case 'D': return 2;
		case 'L': return 3;
		default: cout << "err" << endl; return -1;
	}
}

vector<string> split(string s, char delim) {
    vector<string> res(1);
    for (char c: s) {
        if (c==delim) res.push_back("");
        else res.back()+=c;
    }
    return res;
}
int main() {
string s;
int hx=0, hy=0, tx = 0, ty = 0;
	set<pair<int,int>> been = {{0,0}};
int last = -1; // 0 up, 1 right, 2 down, 3 left
vector<pair<int,int>> all(10);
while (getline(cin,s)) {
	if (!last) {last = dir(s[0]);}
	int n = stoi(split(s,' ')[1]);
	auto check = [&](int j) {
			if (abs(all[j].first-all[j+1].first)>1 or abs(all[j].second-all[j+1].second)>1) {
				all[j+1].first += (all[j].first-all[j+1].first) / (abs(all[j].first-all[j+1].first));
				all[j+1].second+= (all[j].second-all[j+1].second) / (abs(all[j].second-all[j+1].second));
			}
	};
	switch(s[0]) {
		case 'R':
			//hx++;
		f(n) {
			all[0].first++;
			for (int j=0;j<9;j++) {
				check(j);
			}
				been.insert(all[9]);
		}
		break;
		case 'L':
		//hx--;
		f(n) {
				all[0].first--;
			for (int j=0;j<9;j++) {
				check(j);
			}
				been.insert(all[9]);
		}
		break;
		case 'U':
		//hy++;
		f(n) {
				all[0].second++;
			for (int j=0;j<9;j++) {
				check(j);
			}
				been.insert(all[9]);
		}
		break;
		case 'D':
		//hy--;
		f(n) {
				all[0].second--;
			for (int j=0;j<9;j++) {
				check(j);
			}
				been.insert(all[9]);
		}
		break;
	}
}
cout << been.size() << endl;
}
