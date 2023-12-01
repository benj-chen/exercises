// mirrors must be different
#include<iostream>
#include<vector>
using namespace std;
int main() {int t;cin>>t;while(t--){
	// each op: on the left side would push all candidates over
	// on the right side would probably push back
	// test successively larger p would take pn time which is doable with small
	int n; string s; cin>>n>>s;
	// debug: print parities as well as sliding ones
	// were to insert at index idx?
	cout<<"debug "<<s<<": ";
		for (int i=0;i<n;i++) {
			cout << (s[i]==s[n-i-1]);
		}
		cout<<endl;
}}
