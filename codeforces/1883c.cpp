#include<iostream>
#include<vector>
using namespace std;
int main() {int t;cin>>t;while(t--) {
	int n,k;cin>>n>>k;
	vector<int> a(n); for (int i=0;i<n;i++) cin>>a[i];
	if (k==4) {
		// the only number that isn't prime
		// compare result: building 4
		int res1, res2, max_mod = 0;
		for (int& ai: a) {
			ai %= 4;
			if (ai>max_mod) max_mod = ai;
			if (ai==0) {max_mod = 4; break;}
		}
		res1 = k-max_mod;
		// ... or building two 2's
		int num_twos = 0;
		for (int& ai: a) {
			if (ai%2 ==0) num_twos++;
		}
		switch(num_twos) {
			case 0: res2=2; break;
			case 1: res2=1; break;
			default: res2=0;
		}
		cout << (res1<res2? res1:res2) << endl;
	}
	else {
		// if it's not already good, find the highest mod value
		// apply mod(k) to each a
		int max_mod = 0;
		for (int& ai: a){
			ai%=k;
			if (ai>max_mod) max_mod = ai;
			// definitely 0 -- already good
			if (ai==0) {max_mod = k; break;}
		}
		cout << (k-max_mod) << endl;
	}
}
}
