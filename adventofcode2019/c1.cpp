#include<vector>
#include<utility>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
using co = pair<int,int>;
using line = pair<co,co>; // x1,y1; x2,y2;
vector<string> split_delimiter_char(string s, char delim) {
    vector<string> res(1);
    for (char c: s) {
        if (c==delim) res.push_back("");
        else res.back()+=c;
    }
    return res;
}
co make_co(string cmd, co prev) {
    co mult = {0,0};
    switch(cmd[0]) {
        case 'R': mult.first = 1; break;
        case 'L': mult.first = -1; break;
        case 'U': mult.second = 1; break;
        case 'D': mult.second = -1;
    }
    return {prev.first + mult.first * stoi(cmd.substr(1)), prev.second + mult.second * stoi(cmd.substr(1))};
}

bool in_range(int l,int r,int target) {
    // inclusive, l and r can be mixed
    if (l<r)
        return (l<=target and target<=r);
    return r<=target and target<=l;
}

bool intersect(const line& l1, const line& l2) {
    int a=l1.first.first,
    b=l1.first.second,
    c=l1.second.first,
    d=l1.second.second,
    e=l2.first.first,
    f=l2.first.second,
    g=l2.second.first,
    h=l2.second.second,
    res = 0;
    if (b == d)
        return in_range(f,h,d) and in_range(a,c,e);
    return in_range(b,d,h) and in_range(e,g,a);
}
void test_intersect() {
    int a,b,c,d,e,f,g,h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    line l1 = {{a,b},{c,d}},
    l2 = {{e,f},{g,h}};
    cout << intersect(l1,l2) << endl;
}
int main() {
    string in1,in2;
    getline(cin,in1); getline(cin,in2);
    vector<string> _one = split_delimiter_char(in1,','),
                   _two = split_delimiter_char(in2,',');
    // x1,y1; x2,y2
    vector<line> one = {{{0,0},{0,0}}};
    line ln;
    for (string s: _one) {
        one.push_back({one.back().second /* previous spot*/,make_co(s,one.back().second)});
    }
    vector<int> res;
    one.erase(one.begin());

    for (string s: _two) {
        ln.first = ln.second;
        ln.second = make_co(s,ln.second);
        for (line l: one) {
            if (intersect(l,ln)) {
                res.push_back(abs((l.first.first == l.second.first? l.first.first:l.first.second)) + abs((ln.first.first == ln.second.first? ln.first.first: ln.first.second)));
                
            }
        }
    }
    for (int i: res) cout << i << endl;

}