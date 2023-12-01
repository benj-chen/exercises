#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {int t;cin>>t;while(t--){
	int n;cin>>n;
	vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
	// sorted version, compare
	vector<int> w(v.begin(),v.end());
	sort(w.begin(),w.end());
	for (int i=0;i<n;i++) if ((w[i]%2)!=(v[i]%2)) {cout << "no"<<endl;goto end;}
	cout << "yes"<< endl;
end:;
}}
