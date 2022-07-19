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
    one.erase(one.begin());
    vector<vector<int>> res; // index 1, index 2, x, y
    for (int i=0;i<_two.size();i++) {
        ln.first = ln.second;
        ln.second = make_co(_two[i],ln.second);
        for (int j=0;j<one.size();j++) {
            if (intersect(one[j],ln)) {
                res.push_back({
                    i,j,
                    ln.first.first,ln.first.second,ln.second.first,ln.second.second,
                    one[j].first.first,one[j].first.second,one[j].second.first,one[j].second.second,
                });

            }
        }
    }

    for (vector<int> i: res) {
        int sum = 0;
        for (int j=0;j<i[1];j++) {

            sum+=stoi(_one[j].substr(1));
        }
        for (int j=0;j<i[0];j++) {

            sum+=stoi(_two[j].substr(1));
        }
        // dist
        co pt = {(i[2] == i[4]? /* y vals different*/ i[2] : i[6]),
        (i[3] == i[5]? i[3]: i[7])};
        
        switch(_one[i[1]][0]) {
            case 'L': case 'R':
            // horiz
            sum += abs(i[6]-pt.first);break;
            case 'U': case 'D':
            // vert
            sum += abs(i[7]-pt.second);break;
        }
        switch(_two[i[0]][0]) {
            case 'L': case 'R':
            // horiz
            sum += abs(i[2]-pt.first);break;
            case 'U': case 'D':
            // vert
            sum += abs(i[3]-pt.second);break;
        }
      
        cout << sum << endl;
    }

}