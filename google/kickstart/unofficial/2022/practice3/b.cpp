#include<bits/stdc++.h>
using namespace std;
map<char,int> dir {
    {'N',0},
    {'E',1},
    {'S',2},
    {'W',3}
};
map<int,int> dir2 {
	{0,0},
		{2,0},
		{1,1},
		{3,1}};
struct arrow {
    int x,y, di, length=0;
    // di: 0 = n; 1 = e; 2=s;3=w;
        arrow(int x,int y, int di): x(x), y(y), di(di) {}
    
};

bool does_overlap(const arrow& a, const arrow& b) {
	// x
	// short on long DNE
	// long on short
	// chekc 1: x overlap?
	if (a.di == b.di) {
		int same,diff1,diff2,diff3,diff4;
		// normalize
		if (a.di) {
			// l/r
			if (a.y!=b.y) return false;
			same = a.y;
			diff1 = a.x;
			diff2 = a.x+a.length;
			diff3 = b.x;
			diff4 = b.x+b.length;
		}
		else {
			// u/d
			if (a.x!=b.x) return false;
			same = a.x;
			diff1 = a.y;
			diff2 = a.y+a.length;
			diff3 = b.y;
			diff4 = b.y+b.length;
			
		}
		// overlap
		// diff1 in between diff3, diff4?
		if (fmin(diff3,diff4) <= diff1 and diff1 <= fmax(diff3,diff4)) {
			return true;
		}

		if (fmin(diff3,diff4) <= diff2 and diff2 <= fmax(diff3,diff4)) {
			return true;
		}
		// one inside other
		if (fmin(diff1,diff2) <= diff3 and diff3 <= fmax(diff1,diff2)) {
			return true;
		}
		return false;
	}
	// check 2: intersection
	bool cond1 = (fmin(a.x,a.x+a.length) <= b.y and b.y <= fmax(a.x,a.x+a.length));
	bool cond2 = (fmin(a.y,a.y+a.length) <= b.x and b.x <= fmax(a.y,a.y+a.length));
	return cond1 and cond2;
}

int main() {
	arrow a(0,0,1); // west
	a.length = -5;
	arrow b(2,2,0); // north
	a.length = -3;
	cout << does_overlap(a,b) << endl;
	return 0;
int T;cin>>T;T++;for(int t=1;t<T;t++) {
    int n,r,c,sr,sc;
    cin >> n >> r >> c >>
    sr >> sc;
    string di; cin >> di;
    vector<arrow> lines;
    // initial line
    arrow init(sr,sc,dir[di[0]]);
    // length
    int ind = 0;
    while (di[ind]==di[0]) ind++;
    // di[ind] != di[0]
    init.length = ind;
    lines.push_back(init);
    while (ind<n) {
	char init_dir = di[ind];
	int sz =  0;
	while (di[ind] == init_dir) {
		ind++;
		sz++;
	}
	arrow a(0,0,dir2[dir[init_dir]]);
	a.length = sz * (dir[init_dir] > 1? -1: 1);
	lines.push_back(a);
    }
    for (int i=1;i<lines.size();i++) {
	    // upd init loc
	    int x1,y1,x2,y2;
	    if (lines[i-1].di) {
		    // odd: horiz
		    lines[i].x = lines[i-1].x+lines[i-1].length;
		    lines[i].y = lines[i-1].y;
		    x1 = lines[i].x; x2 = lines[i].x+lines[i].length;
	    }
	    else {
		    // even
		    lines[i].y = lines[i-1].y+lines[i-1].length;
		    lines[i].x = lines[i-1].x;
		    y1 = lines[i].y; y2 = lines[i].y+lines[i].length;
		    x1 = lines[i].x; x2 = x1;
	    }
	    // upd length
	    
    }
    // cout << "arrows: " << endl;
    // for (auto i: lines) {
	    // cout << i.x << " " << i.y << " " << i.di << " " << i.length << endl;
    // }

}
}
