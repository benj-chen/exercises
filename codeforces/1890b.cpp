#include<iostream>
#include<vector>
using namespace std;
int main() {int t; cin>>t;while(t--) {
	int n,m; cin >> n >> m;
	string s,t; cin>>s>>t;
	// look at end cases for t
	// only need to fix broken parts
	// if ends of t = ends of broken parts its joever
	char ts = t[0], te = t.back();
	int t_needed = 0
		;
	for (int i=1;i<n;i++) {
		if (s[i-1]==s[i]) {
			t_needed++;
			if (s[i-1]==ts or s[i]==te) {
				cout <<"No" << endl;
				goto end;
			}
		}
	}
	if (t_needed){
		
	// if t is not good it only works if s is already good
		for (int ti = 1;ti<m;ti++) {
			if (t[ti-1]==t[ti]) {
				cout << "No" << endl;
				goto end;
			}
		}
	}
	cout << "Yes"<<endl;
end:;
}}
