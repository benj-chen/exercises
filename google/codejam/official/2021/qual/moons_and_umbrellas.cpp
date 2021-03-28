#include <bits/stdc++.h>
using namespace std;
#define f first
int main() {
    // ifstream cin("input.txt");

    int T;
    cin >> T;
    T++;
    for (int t=1;t<T;t++) {

        int x,y;
        string s;
        cin >> x >> y >> s;
        cout << "Case #" << t << ": ";
        int fi=0,bi=s.length()-1;
        // cout << endl;
        while (s[fi++]=='?') {
        }
        while (s[bi--]=='?') {
        }
        
        s=s.substr(fi-1,bi+2-fi+1);
        vector<pair<int,int> > locs; // each pair is
        // inclusive, inclusive
        for (int i=1;i<s.length();i++) {
            if (s[i]=='?') {
                if (s[i-1]!='?') {
                    // new
                    locs.push_back(make_pair(i,i));
                }
                else {
                    // attached
                    locs.back().second++;
                }
            }
        }
        int m=fmax(x,y);
        map<string,int> score=
        {
            {"CJ",x},
            {"JC",y},
            {"CC",0},
            {"JJ",0}
        };
        int sum=0;
        for (pair<int,int> p: locs) {
            sum+=score[string(1,s[p.f-1])+string(1,s[p.second+1])];
            }
        for (int i=1;i<s.length();i++) {
            if (s[i]!='?' && s[i-1]!='?') {
                sum+=score[string(1,s[i-1]) + string(1,s[i])];
            }
        }
        cout << sum << endl;
    }
}