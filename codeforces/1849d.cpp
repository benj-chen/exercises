#include<iostream>
#include<vector>
using namespace std;
vector<int> a; int n;
int proc(int st) {
	/*
	if (st==n-1) {
		// must activate
		return 1;
	}
	// activate the front and spread right
	int i=st; while (a[i]) {i++; if (i==n) return 1;}
	// a[i] is empty and can't continue the spread
	int res1 = 1+proc(i), res2=1e9;

	// rely on the next thing to activate
	if (a[st+1]) {
		a[st+1]--;
		res2 = proc(st+1);
		a[st+1]++;
	}
	return res1<res2? res1: res2;
	*/
}
int main() {
	cin >>n;
	a.clear();a.resize(n); for (int i=0;i<n;i++) cin >> a[i];
	// how many switches can you turn on
	// for any that you turn on, either left, or right, or (if 2) both
	cout << proc(0) << endl;
}
