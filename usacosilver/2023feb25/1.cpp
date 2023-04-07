#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
#include<cmath>

#define f3(v,st,sp,se) for (int v=st;v<sp;v+=se)
#define f2(v,st,sp) for (int v=st;v<sp;v++)
#define f1(v,sp) for (int v=0;v<sp;v++)
#define f(sp) for (int i=0;i<sp;i++)

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
int t; cin >> t; f1(T,t) {
	// find max c (x) and m (y)
	int n,a,b; cin >> n >> a >> b;
	int mix=a,miy=b, max = 0, may = 0;
	vvi inputs(n, vi(3));
	f(n) {
		cin >> inputs[i][0] >>inputs[i][1] >>inputs[i][2];
		int q = (inputs[i][2]-inputs[i][1])/inputs[i][0]; // assume y is 1
		mix = fmin(mix,q); // assume y is 1
		miy = fmin(miy,q); // assume x is 1
		max= fmax(max,q);
		may= fmax(may,q);
	}
	cout << mix << miy << max << may <<endl;
	// binary search the amount of headspace
	
}
}
