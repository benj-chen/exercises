#include <iostream>
#include <map>
#include <vector>
// previously did day 1 early
#include <fstream>
#include <utility>
using namespace std;
ifstream fin("in");
using str=string;
using vs = vector<str>;
vs split(str s, char delim) {
    vs ret(1);
    for (char c: s) {
        if (c==delim) ret.push_back("");
        else ret.back()+=str(1,c);
    }
    return ret;
}
int main() {
    string a1,b1; fin >> a1 >> b1;
    vs a = split(a1,','), b = split(b1,',');
    vector<pair<int,int>> v,res;
    char last = '3';
    int x=0,y=0;
    for (str i: a) {
        int num = stoi(i.substr(1));
        switch(i[0]) {
            case 'R':
            x+=num;
            break;
            case 'L':
            x-=num;
            break;
            case 'U':
            y+=num;
            break;
            case 'D':
            y-=num;
            break;
        }
        if (i[0] == last) {
            cout << "bad assumption" << endl;
        }
        last = i[0];
        v.push_back(make_pair(x,y));
    }
    x = 0, y = 0;
    last = '3';

    map<char,char> opp = {
        {'R','L'},
        {'L','R'},
        {'U','D'},
        {'D','U'},
    };
    for (str i: b) {
        int num = stoi(i.substr(1));
        switch(i[0]) {
            case 'R':
            x+=num;
            break;
            case 'L':
            x-=num;
            break;
            case 'U':
            y+=num;
            break;
            case 'D':
            y-=num;
            break;
        }
        if (i[0] == last or i[0] == opp[last]) {
            cout << "bad assumption" << endl;
        }
        using pii = pair<int,int>;
        // find pairs where x or y is common and compare to the pairs before  and after (visually, it doesn't seem to give the same direction twice)
        int lx=0, ly=0; // impossible to get on frame 1
        for (pii p: v) {
            if (p.first == x) {
                // check if y is good
                if (p.second>ly) {
                    if (ly <= y and y <= p.second) {
                        // match
                        res.push_back(make_pair(x,y));
                    }
                }
                else {
                    if (p.second <= y and y <= ly) {
                        res.push_back(make_pair(x,y));
                    }
                }
            }
            if (p.second == y) {
                // check if x is good
                if (p.first>lx) {
                    if (lx <= x and x <= p.first) {
                        // match
                        res.push_back(make_pair(x,y));
                    }
                }
                else {
                    if (p.first <= x and x <= lx) {
                        res.push_back(make_pair(x,y));
                    }
                }
 
            }
            lx = p.first;
            ly = p.second;
        }
        cout << x << " " << y << endl;
    }
}