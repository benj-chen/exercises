#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n,k,t; cin>>n>>k>>t;
	vector<int> a(k+1),results(n),output(n); // results: amount of space moved
	for (int i=0;i<k;i++)cin>>a[i];
	a[k]=n;
	for (int i=0;i<k;i++) {
		// behavior for [a[i],a[i+1]) will be sim
		// we are still processing in the order from 1...n-1
		int amt = a[i+1]-a[i];
		for (int j=a[i];j<a[i+1];j++) {
			results[j] =j+ (t - t%amt) % n; // floor by amt, then divide by n to get circular value
		}
		for (int mod = 1; mod <= t % amt; mod++){
			// results[i] gets moved if the mod is 1, results[i+1] if 2, etc
			results[a[i]+mod-1]+=amt;
		}
	}
	for (int i=0;i<n;i++) {
		output[results[i]%n]=i;
	}
	cout<<output[0];
	for (int i=1;i<n;i++) cout<<' '<<output[i];
	cout<<endl;
}
