#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() { int t;cin>>t;while(t--){

	int n;cin>>n;
	vector<int> a(n);
	map<int,int> m;
	int in;
	for (int i=0;i<n;i++) {
		cin>>in;
		m[in]++;
	}
	//must alternate
	bool ans=0;
	switch(m.size()) {
		case 2:
			ans=(n-m[in] < m[in] + 2 and n-m[in] > m[in]-2);break;
		case 1:
			ans=1;
			break;
	}
	cout << (ans? "Yes": "No")  << endl;
	/*
	int totalsum=0; for (int i: a) totalsum+=i;
	totalsum<<=1;
	for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) {
		if ((totalsum-a[i]-a[j])%(n-1)==0) {
			cout << "Yes" << endl;
			goto end;
		}
	}
	cout << "No" << endl;
end:;
*/
}
}
