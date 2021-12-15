#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

vi split_delimiter_char(string s, char delim) {
    vi res;
    string cur_num="";
    for (char c: s) {
        if (c==delim) {res.push_back(stoi(cur_num)); cur_num = "";}
        else cur_num+=string(1,c);
    }
    if (cur_num!="") res.push_back(stoi(cur_num));
    return res;
}
int sumrange(int st, int end) {
    if (end) return (st+end)*(end-st+1)>>1;
    return 0;
}
int main() {
    string s;
    cin>>s;
    vi pos = split_delimiter_char(s,','), score;
    sort(pos.begin(),pos.end());
    for (int i=pos.front();i<=pos.back();i++) {
        score.push_back(0);
        for (int j: pos)
            score.back()+=abs(i-j);
    }
    int lo = score.front();
    for (int i: score)
        lo = fmin(lo,i);
    cout<<lo<<endl;
}