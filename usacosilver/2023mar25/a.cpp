#include<iostream>
#include<assert.h>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cmath>

#define f3(v,st,sp,se) for (int v=st;v<sp;v+=se)
#define f2(v,st,sp) for (int v=st;v<sp;v++)
#define f1(v,sp) for (int v=0;v<sp;v++)
#define f(sp) for (int i=0;i<sp;i++)
using namespace std;
int bs(vector<int>& ls, int x, int st, int end) {
	if (ls[st]>=x) return st;
	if (st + 1 == end or end + 1 == st or st == end) {
		if (ls[fmin(st,end)] >= x) return fmin(st,end);
		if (ls[fmax(st,end)] >= x) return fmax(st,end);
		assert(ls[fmax(st,end)+1] >= x);
		return fmax(st,end)+1;
	}
	int mid = (st+end)/2;
	if (ls[mid]==x) return mid;
	if (ls[mid] < x) return bs(ls,x,mid+1,end);
	if (ls[mid] > x) return bs(ls,x,st,mid-1);
}
/*
	// find the index whose value is strictly greater than the val
	// st and end are included in the result
	if (val < v[st]) return st;
	if (val > v[end]) return end+1;
	if (st + 3 > end) {
		// st, st+1, or st+2 is end; we know that val is one of this
		if (val < v[st+1]) return st+1;
		if (val < v[st+2]) return st+2;
		return st+3;

	}
	if (st==end) return(v[st]==val);
	int mid = (st+end)/2;
	if (v[mid] == val) return mid;
	if (v[mid] < val) return bs(v,val,mid+1,end);
	if (v[mid] > val) return bs(v,val,st,mid-1);
}
*/

int naive_search(vector<int>& v, int val) {
	f(v.size()) {
		if (v[i]> val) return i;
	}
	return v.size();
}
int main() {
	vector<int> w = {1,2,2,5,6};
	//cout << bs(w,2,0,4) <<endl<< bs(w,3,0,4) <<endl<< bs(w,0,0,4) <<endl<< bs(w,5,0,4) <<endl<< bs(w,6,0,4) << endl << endl;
	vector<int> e = {1,2,4,6,10};
	//cout << bs(e,1,0,5) << " " << bs(e,5,0,5) << endl;
	int n,q; cin >> n;
	vector<array<int,2>> ov(n);
	map<int,int> c;
	f(n) {
		cin >> ov[i][0];
		ov[i][1] = i;
	}
	sort(ov.begin(),ov.end());
	f(n) {
		c[ov[i][1]+1] = i;
	}
	for (auto i: ov) {
		for (auto j: i) {
			//cout << j << " ";
		}
		//cout << endl;
	}
	vector<int> v;
	for (auto i: ov) {
		v.push_back(i[0]);
	}
	// make prefix sums
	vector<int> ps = {0};
	for (int i: v) {
		ps.push_back(ps.back()+i);
	}
	// calculate base thing
	int count = 1;
	long long base = 0;
	for (int i: v) {
		base += count*i;
		count++;
	}
	//cout << base << "base" << endl;
	cin >> q;
	v.insert(v.begin(),-1);
	v.push_back(1e9);
	f(q) {
		int a, b; cin >> a >> b;
		int init_index = c[a]+1;
		int new_index = bs(v,b,0,v.size());
		//cout << init_index << " " << new_index;
		if (new_index > init_index and new_index >= 2) new_index--;
		long long ans = base;
		ans -= (init_index) * v[init_index];
		ans += (new_index) * b;
		//cout << ans << "_1"<<endl;
		if (init_index > new_index) {
			ans += (ps[init_index-1]-ps[new_index-1]);
		}
		else {
			ans-=(ps[new_index]-ps[init_index]);
		}
		
		cout << ans << endl;
	}

}
