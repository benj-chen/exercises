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

int binary_search_up(vvi& v, int i, int l, int r) {

    if (r > l) {
        int mid = l + (r - l) / 2;
        if (v[mid][0] == i)
            return mid;
        if (v[mid][0] > i)
            return binary_search_up(v, i, l, mid - 1);
        return binary_search_up(v, i, mid + 1, r);
    }
    return l; // snap up
}
int main() {
	/*cjjj
	vvi v = {{100},{200}};
	cout << 
		binary_search_up(v,100,0,2) <<
		binary_search_up(v,200,0,2) <<
		binary_search_up(v,240,0,2) <<
		binary_search_up(v,50,0,2) << endl;
		*/
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
				  cout << gr.size() << endl;
	for (vi v: gr) {
		cout << v[0] << v[1] << v[2] << " ";
	}
	cout << endl;
	cout << "sz" << gr.size() << endl;
	cout << "ignore: ";
	f1(q,n) {
		cout << "r"<<res << endl;
		int x,y,t; cin >> x >> y >> t;
		// find the two in between
		int ind = binary_search_up(gr,t,0,g);
		cout << ind << endl;
		//cout << q <<" "<< ind << endl;
		// ind must make it to cur must make it to ind+1 in allotted time
		int time_needed;
		// check prev
		if (ind>g-2) {
cout << gr[ind-1][0] << endl;
		ind = g-1;
		time_needed = abs(x-gr[ind][1]) + abs(y-gr[ind][2]);
		//cout << time_needed << endl;
		if (time_needed <= abs(t-gr[ind][0])) {
			continue;
		}
		}
		else if (ind == 0 and t <gr[ind][0]) {
cout << gr[ind][0] << endl;

		time_needed = abs(x-gr[ind][1]) + abs(y-gr[ind][2]);
		//cout << time_needed << endl;
		if (time_needed <= abs(t-gr[ind][0])) {
			//cout<<"yes"<<endl;
			continue;
		}
		}
		else if (gr[ind][0]==t) {
			// must match
			if (x!=gr[ind][1] or y!=gr[ind][2]) {
				res++;
				continue;
			}
			continue;
		}


		else {
cout << gr[ind][0] << " " << gr[ind+1][0] << endl;
		time_needed = abs(x-gr[ind][1]) + abs(y-gr[ind][2]);
		//cout << time_needed << endl;
		bool res1=(time_needed <= abs(t-gr[ind][0]));
		ind++;

		time_needed = abs(x-gr[ind][1]) + abs(y-gr[ind][2]);
		//cout << time_needed << endl;
		bool res2 = (time_needed <= abs(t-gr[ind][0]));
		if (res1 and res2) {
			;
		}
		else res++;
		continue;
		}
		
	
		res++;
	}

	cout << res << endl;
}
