#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cmath>

#define f3(v,st,sp,se) for (int v=st;v<sp;v+=se)
#define f2(v,st,sp) for (int v=st;v<sp;v++)
#define f1(v,sp) for (int v=0;v<sp;v++)
#define f(sp) for (int i=0;i<sp;i++)
using namespace std;
int get_bits(int a, int b) {
	int res = a ^ b;
	int ct=0;
	while (res != 0) {
		if (res % 2) {
			ct++;
		}
		res >>=1;
	}
	return ct;
}
int main() {
	//testing
	int c,n; cin >> c >> n;
	vector<int> v(n),maxes(n);
	f(n) {
		maxes[i] = 0;
		string s;
		cin >> s;
		int num = 0;
		// convert s to a 1,0 number
		f1(j,c) {
			num <<= 1;
			if(s[j]=='G') { num++;}
		}
		v[i]=num;
	}

	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			int q = get_bits(v[i],v[j]);
			maxes[i] = fmax(maxes[i],q);
			maxes[j] = fmax(maxes[j],q);

		}
	}
	for (int i: maxes) cout <<i << endl;
}
