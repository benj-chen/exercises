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
	for (int i=1;i<v.size()-1;i++){
		char m1 = 0, m2 = 0;
		for (int j=1;j<v[0].size()-1;j++) {
			m1 = fmax(m1, v[i][j-1]);
			if (v[i][j] > m1) {
				goods.insert(conv(i,j));
			}
		}
		for (int j=v[0].size()-2;j>0;j--) {
			m2 = fmax(m2, v[i][j+1]);
			if (v[i][j]>m2) {
				goods.insert(conv(i,j));
			}
		}
	}
	for (int i=1;i<v[0].size()-1;i++){
		
		char m1 = 0, m2 = 0;
		for (int j=1;j<v.size()-1;j++) {
			m1 = fmax(m1, v[j-1][i]);
			if (v[j][i] > m1) {
				goods.insert(conv(j,i));
			}
		}
		for (int j=v.size()-2;j>0;j--) {
			m2 = fmax(m2, v[j+1][i]);
			if (v[j][i]>m2) {
				goods.insert(conv(j,i));
			}
		}
	}
	cout << goods.size()+v.size()*2 + (v[0].size()-2)*2 << endl;
}
