
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<utility>

#define f3(v,st,sp,se) for (int v=st;v<sp;v+=se)
#define f2(v,st,sp) for (int v=st;v<sp;v++)
#define f1(v,sp) for (int v=0;v<sp;v++)
#define f(sp) for (int i=0;i<sp;i++)
using namespace std;
map<int,char> nex {
	{0,'b'},
	{1,'e'},
	{2,'s'},
	{3,'s'},
	{4,'i'},
	{5,'e'}
};
long long total_count = 0;
map<string, pair<int,int>> cache
= {
	{"",{1,0}}};
//map<int,pair<int,int>> cache;
pair<int,int> count(string s) {
	if (cache[s].first) {
		//total_count += cache[s].first -1;
		return cache[s];
	}
	// CACHE
	// look forward
	if (s.size() ==0) {
		return make_pair(1,0);
	}
	pair<int,int> prev = count(s.substr(0,s.size()-1));
	if (s.back() == nex[prev.second]) {
		prev.second++;
	}

	if (prev.second == 6) {
		prev.first++;
		prev.second = 0;
	}
	//total_count += prev.first-1;
	cache[s] = prev;
	return prev;
	
}
int main1() {
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++) {
		for (int j=i+1;j<s.size();j++) {
			count(s.substr(i,j-i+1));
			total_count += cache[s.substr(i,j-i+1)].first-1;
		}
	}
	cout << total_count << endl;
}
int main2() {
	string s; cin >> s;
	for (int i=0;i<s.size()-5;i++) {
		int res = (s[i]=='b');
		for (int j=i+1;j<s.size();j++) {
			if (s[j] == nex[res%6]) {
				res++;
			}
			total_count += res/6;
		}
	}
	cout << total_count << endl;
	return 0;
}
int main3() {
	// N time pass through to find bessie locations
	string s; cin >> s;
	vector<pair<int,int>> v; // "b" index; residue value
	for (int i=0;i<s.size();i++) {
		if (s[i] == 'b') {
			v.push_back({i,1});
		}
		
	}
	// N^2 math
}
int main() {
	return main2();
	string s; cin >> s;
	vector<int> g;
	// find "bessie" locations
	if (s.size() < 6) {
		cout << 0<<endl;return 0;
	}
for (int i=0;i<s.size()-5;i++) {
		if (s.substr(i,6) == "bessie") {
			g.push_back(i);
		}
	}
	// indices start at the thing and its 'e' is at i+5
	// do 0 and final sep
	for (int i=1;i<g.size()-1;i++) {
		int d1 = g[i-1]+1, d2 = g[i], d3=g[i]+6, d4=g[i+1]+5;
		total_count += (d2-d1+1) * (d4-d3+1);
	}
	if (g.size()==0) {
		cout << 0 << endl; return 0;}
	if (g.size() ==1) {
		total_count += (g[0]+1) * (g.size()-g[0]-5);
	}
	if (g.size() > 1) {
		int d3=g[0]+6,d4=g[1]+5;
		total_count += (d4-d3+1);
		int d1 = g[g.size()-2]+1, d2=g[g.size()-1];
		total_count += (d2-d1+1);
	}
	cout << total_count << endl;
}
/*
int main() {

	string s; cin >> s;
	f(s.size()) {
		cache[i] = {0,int(s[i]=='b')};
		for (int j=i+1;j<s.size();j++) {
			cache[j] = {cache[j-1].first + (cache[j-1].second == 5 and s[j] == 'e'),(cache[j-1].second + (cache[j-1].second == nex[s[j]])) % 6};
			total_count += cache[j].first;
		}
	}
	cout << total_count << endl;
}
*/
