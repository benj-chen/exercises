#include<iostream>
#include<vector>
#include<set>
#define f(n) for (int i=0;i<n;i++)
using namespace std;
pair<int,int>conv(int a, int b) {
	return make_pair(a,b);
        //return ((long long)(a)<<32) + b;
}
int abs(int i) {
	if (i<0) return -i;
	if (i==0) return 1;
	return i;
}
int dir(char c) {
	switch(c) {
		case 'U': return 0;
		case 'R': return 1;
		case 'D': return 2;
		case 'L': return 3;
		default: cout << "err" << endl; return -1;
	}
}

vector<string> split(string s, char delim) {
    vector<string> res(1);
    for (char c: s) {
        if (c==delim) res.push_back("");
        else res.back()+=c;
    }
    return res;
}
int main() {
string s;
int hx=0, hy=0, tx = 0, ty = 0;
	set<pair<int,int>> been = {{0,0}};
int last = -1; // 0 up, 1 right, 2 down, 3 left
while (getline(cin,s)) {
	if (!last) {last = dir(s[0]);}
	int n = stoi(split(s,' ')[1]);
	/*
	if (last==dir(s[0]) {
		// same direction easy
		switch(dir) {
			case 0: hy += n; ty += n;
			break;
			case 1: hx += n; tx += n;
			break;
			case 2: hy -= n; ty -= n;
			break;
			case 3: hx -= n; tx-=n;
			break;
		}	
	}
	if (abs(last-dir(s[0]) == 1)) {
		// left/right turn
		
	}
	*/
	auto check = [&]() {
			if (abs(hx-tx)>1 or abs(hy-ty)>1) {
				tx += (hx-tx) / (abs(hx-tx));
				ty += (hy-ty) / (abs(hy-ty));
			}
			been.insert(conv(tx,ty));
	};
	switch(s[0]) {
		case 'R':
			//hx++;
		f(n) {
			hx++;
			check();
		}
		break;
		case 'L':
		//hx--;
		f(n) {
			hx--;
			check();
		}
		break;
		case 'U':
		//hy++;
		f(n) {
			hy++;
			check();
		}
		break;
		case 'D':
		//hy--;
		f(n) {
			hy--;
			check();
		}
		break;
	}
}
cout << been.size() << endl;
}
