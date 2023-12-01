#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
using namespace std;
using vi = vector<int>;
bool lt(vi a, vi b) {
	for (int i=0;i<a.size();i++) {
		if (a[i]<b[i]) return true;
	}
	return false;
}
int main() {int t;cin>>t;while(t--){
	int n,q; cin >> n; 
	vi a(n);
	for (int i=0;i<n;i++)cin>>a[i];
	cin>>q;
	// collect all queries before processing
	// indices are one-indexed.
	vector<array<int,4>> queries(q);
	// insert dummy query
	//queries[0] = {1,n,0,0};
	vi best = a;
	for(int Q=0;Q<q;Q++){
		int i,j,x;cin>>i>>j>>x;
		for (int d = i-1;d<j;d++) {
			a[d]+=x;
		}
		for (int i=0;i<n;i++) cout << a[i] << "," << best[i] << " ";
		cout << endl;

		if (x<0 and lt(a,best)) best=a;
		//cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
		//queries[i][3] = i; // keep track
	}
	
	//sort(queries.begin(),queries.end());
	// if the k'th query lowers the earliest element the most (nonzero),
	// the resulting array has to be after that happens
	// at which point we care about what happens to the next-earliest element.
	// initial check: if there are no negative values, no point in trying.
	// probably has to be faster than o(qn)
	cout << best[0];
	for (int i=1;i<n;i++) cout << " " << best[i];
	cout << endl;
}}
