#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<deque>
#define f(n) for (int i=0;i<n;i++)
#define ff(i,n) for (int i=0;i<n;i++)
#define fff(i,m,n) for (int i=m;i<n;i++)
using namespace std;
using vi = vector<int>;
using ll = long long;

int main(){int T;cin>>T;ff(t,T){
	int l,n; cin >> l >> n;
	char dir = ' ';
	long long subtotal = 0, res = 0, pos = 0;
	f(n) {
		int j;
		char c;
		cin >> j >> c;
		if (dir==' ') dir = c;
		if (c==dir) {
			subtotal+=j;
		}
		else {
			if (dir=='C') pos += subtotal;
			else pos -= subtotal;
			int true_pos = pos % l;
			pos = abs(pos);
			res += pos/l;
			pos = true_pos;
			dir = c;
			subtotal = j;
		}
		cout << pos << " " << subtotal << " " << res << endl;
	}
			if (dir=='C') pos += subtotal;
			else pos -= subtotal;
			int true_pos = pos % l;
			pos = abs(pos);
			res += pos/l;
			pos = true_pos;
	
	cout << "Case #" << t+1 << ": " << res << endl;

}}
