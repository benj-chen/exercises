// I was goofy and didn't realize that all it asked was that the remaining chars can be rearranged. this would work assuming that you couldn't
#include<iostream>
#include<vector>
using namespace std;

int main() { int t;cin>>t;while(t--) {
	int N,K; string s;cin>>N>>K>>s;
	// dp: at any point if the front and back are diff, must remove one
	bool dp[N+1][N+1][K+1];
	for (int i=0;i<=N;i++) for(int j=0;j<=N;j++){
		if (j+i>N) continue;

		for (int k=0;k<=K;k++) {
		// i is the length, j is the starting index
		// end index is i+j
		if (i==0) dp[i][j][k] = (k==0);
		else if (i==1) dp[i][j][k]=(k<2);
		else if (s[i]==s[i+j-1]) dp[i][j][k] = 
			(j<N-1 		? dp[i-2][j+1][k] : 0) or
			(j<N-1 and k>1 	? dp[i-2][j+1][k-2]: 0);
		else dp[i][j][k] =
			(k>0		? dp[i-1][j][k-1]: 0) or
			(k>0 and j<N-1	? dp[i-1][j+1][k-1]: 0);
	}}
	cout << "debug" << endl;
	while (s != "end") {
		int i,j,k; cin>>i>>j>>k;
		cout << dp[i][j][k] << endl;
	}
	cout << "for " << s << ": " <<(dp[N][0][K] ? "YES":"NO") << endl;
}}
