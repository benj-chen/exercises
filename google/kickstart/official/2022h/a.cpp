#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
// #include<priority_queue>
#include<deque>
#include<utility>
#define f(n) for (int i=0;i<n;i++)
#define ff(i,n) for (int i=0;i<n;i++)
#define fff(i,m,n) for (int i=m;i<n;i++)
using namespace std;
using vi = vector<int>;
using ll = long long;

int main(){int T;cin>>T;T++;fff(t,1,T){
	int l,n,j; cin >> l >> n;
	// use pos to denote clockwise, neg to denote anticl
	char c;
	cin >> j >> c;
	int cur_pos =0;
	char dir = c; // 1 = clockwise
	int res = 0;
	int subtotal = j;
	f(n-1) {
		cin >> j >> c;
		if (c==dir) {
			subtotal += j;
		}
		else {
			res += subtotal/l;
			int pre = cur_pos;
			if (dir=='C') cur_pos += subtotal%l;
			else cur_pos -= subtotal%l;
			if (cur_pos >= l or cur_pos <= l) {
				cur_pos = abs(cur_pos);
				res += cur_pos/l;
				cur_pos = cur_pos % l;
				if (dir=='A') cur_pos *= -1;
			}
			// if ((pre > 0 and cur_pos < 0) or 
				// (pre < 0 and cur_pos > 0)) {
				// res++;
			// }
			if (dir=='A' and cur_pos >0) cur_pos *= -1;
			cout
				<< " " << i
				<< " " << subtotal
				<< " " << res
				<< " " << cur_pos
				<< endl;

			dir = c;
			subtotal = j;
			// cout <<i << " " << res << " " << pre << " " << subtotal <<" " << cur_pos << " " << dir << endl;
		}
	}
	// f(n) {
		// cin >> j >> c;
		// if ((c=='C') != dir) {
			// cur_pos -= j;
			// dir = !dir;
		// }
		// else {
			// cur_pos += j;
		// }
		// // adj if cur_pos went out of range


	// }
	cout << "Case #" << t << ": " << res <<
	       	endl;
}}
