#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main() {int t;cin>>t;while(t--){
	// there will always be one central node?
	// start from completed and remove one at a time until it doesn't work
	int n,c; cin>>n>>c;
	vector<int> a(n);for(int i=0;i<n;i++) cin>>a[i];
	// keep hugest sum contributors
	int sum=0; for (int i=0;i<n;i++) sum+=a[i];
	//vector<bool> on(n); for (int i=0;i<n;i++) on[i]=1;
	set<int> on; for (int i=0;i<n;i++) on.insert(i);
	for (int j=0;j<n-1;j++) {
		// start from completed and remove one at a time until it doesn't work
		// n^2 is ok
		// prioritize by smallest diff between the left and right expression
		// process smallest separately
		int minia=1e9, minib=1e9,mindiff = 1e9, choseni=-1;
		for (int i: on) {
			if (i<minia) {
				minib = minia;
				minia = i;
			}
			else if (i<minib) minib=i;
		}
		int u = sum - a[minia] - (minia+1)*(minib+1)*c;
		if (0<=u and u < mindiff) {
			mindiff = u;
			choseni = minia;
		}
		for (int i: on) if (i!=minia){
			u = sum - a[i] - (minia+1)*(i+1)*c;
			if (0<=u and u < mindiff){
			
				mindiff = sum - a[i] - (minia+1)*(i+1)*c ;
				choseni = i;
			}
		}
		if (choseni==-1) {
			cout << "No" << endl;
			goto end;
		}
		cout << "remove " << choseni+1 << ": " << a[choseni];
		sum -= a[choseni];
		on.erase(choseni);
		/*
		// prioritize by smallest a value
		int mina = 1e9, mini = -1;
		for (int j=0;j<n;j++) if (on[j]) {
			if (a[j]<mina) {
				mina = a[j]; mini=j;
			}
		}
		// equation holds?
		cout << "choosing " << mini << " = " << mina << endl;
		sum -= mina;
		on[mini]=0;
		int j=-1;
		for (j=0;j<n;j++) if (on[j]) break;
		if (sum < c*(mini+1)*(j+1)) {
			cout << "No" << endl;
			goto end;
		}
		*/
	}
	cout << "Yes" << endl;
end:;
}}
