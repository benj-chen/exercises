#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
long long conv(int a, int b) {
	return ((long long)(a)<<32) + b;
}
int main() {
	string s;
	vector<string> v;
	set<long long> goods;
	while (getline(cin,s)) {
		v.push_back(s);
	}
	int high_score = 0;
	for (int i=0;i<v.size();i++) for (int j=0;j<v[0].size();j++) {

		// up
		int a=i, b=j, score=1;
		while (0<a and v[--a][b] < v[i][j]);
		score *= i-a;
		a=i;
		// down
		while (a<v.size()-1 and v[++a][b]<v[i][j]);
		score *= a-i;
		a=i;
		// left
		while (0<b and v[a][--b] < v[i][j]);
		score *= j-b;
		b=j;
		// right
		while (b<v.size()-1 and v[a][++b]<v[i][j]);
		score *= b-j;
		high_score = fmax(high_score, score);
	}
	cout << high_score << endl;
}
