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
#include<assert.h>

#define f3(v,st,sp,se) for (int v=st;v<sp;v+=se)
#define f2(v,st,sp) for (int v=st;v<sp;v++)
#define f1(v,sp) for (int v=0;v<sp;v++)
#define f(sp) for (int i=0;i<sp;i++)

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int binar(vvi& v, int i, int l, int r) {

    if (r > l) {
        int mid = l + (r - l) / 2;
        if (v[mid][0] == i)
            return mid;
        if (v[mid][0] > i)
            return binar(v, i, l, mid - 1);
        return binar(v, i, mid + 1, r);
    }
    return l; // snap up
}
int binary_search_up(vvi& v, int i, int l, int r) {
	int res = binar(v,i,l,r);
	if (0 < res and res < r) {
		// normal
		
		if (v[res][0] <= i and i <= v[res+1][0]);
		if (v[res][0] > i) res--;
		if (v[res+1][0] < i) res++;
		assert(v[res][0]<=i and i<=v[res+1][0]);
	}
	if (res==r) {
		
		if (v[r][0] > i) res--;
		assert(v[res][0]<=i);
		if (res!=r) assert(i<=v[res+1][0]);
	}
	if (res==0) {
		if (v[0][0] <= i) {
			if (v[1][0] <=i) {
				res++;
			}
		}
		else {

		}
		assert ((v[res][0] <= i and i <= v[res+1][0]) or i<=v[res][0]);
	}
	return res;
}
int main() {
	int res = 0;
	int g, n;
	cin >> g >> n
		;
	vvi gr(g,vi(3));
	
	f(g) {
		cin >> gr[i][1] >> gr[i][2] >> gr[i][0];
	}
	// sort on g
	sort(gr.begin(),gr.end()); // by time
				   /*
				  cout << gr.size() << endl;
	for (vi v: gr) {
		cout << v[0] << v[1] << v[2] << " ";
	}
	cout << endl;
	cout << "sz" << gr.size() << endl;
	cout <<
		binary_search_up(gr,50,0,g-1) << endl << // 0
		binary_search_up(gr,100,0,g-1) << endl << //1
		binary_search_up(gr,140,0,g-1) << endl << //1
		binary_search_up(gr,200,0,g-1) << endl << //2
		binary_search_up(gr,240,0,g-1) << endl << //2
		binary_search_up(gr,400,0,g-1) << endl << //3
		binary_search_up(gr,450,0,g-1) << endl << //3
		endl;
	*/
	f1(q,n) {
		int x,y,t; cin >> x >> y >> t;
		int ind = binary_search_up(gr,t,0,g-1);
		//cout << "i" << ind << endl;
		auto check = [&](int i) {
			//int time_needed = abs(x-gr[i][1]) + abs(y-gr[i][2]);
			int x_ = abs(x-gr[i][1]),
			    y_ =
				abs(y-gr[i][2]);
			int time_needed = ceil(sqrt(x_*x_ + y_*y_));
			//cout << time_needed << "vs" <<abs(t-gr[i][0])<< endl;
			if (time_needed > abs(t-gr[i][0])) {
				return true; // cannot make it = innocent
			}
			return false;
		};



		if (ind==0 and t < gr[0][0]) {
			//cout << "type1" << ind << endl;
			// only check 0
			if (check(ind)) {
				res++;

			}
		}
		else if (ind == g-1 and t > gr[ind][0]) {
			//cout << "type2" << ind << endl;
			// end, definitely greater than final t
			if (check(g-1)) {
				res++;
			}
		}
		else if (t==gr[ind][0]) {
			//cout << "type3" << ind << endl;
			//s ame
			if (abs(x-gr[ind][1]) + abs(y-gr[ind][2])) {
				res++;
			}
		}
		else {
			//cout << "type4" << ind << endl;
			// defualt, look at and plus 1
			//cout << check(ind) << endl<< check(ind+1) << endl;
			if (check(ind) or check(ind+1)) {
				res++;
			}
		}
	}
		cout << res << endl;
}
