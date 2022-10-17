#include<bits/stdc++.h>
using namespace std;
int main() {
int T;cin>>T;T++;for(int t=1;t<T;t++){
    int    n,   r,   c,   sr,   sc;
    cin >> n >> r >> c >> sr >> sc;
    r++;c++;
    string s;
    cin >> s;
    // bool been[c][r] = {}; // access: [sr][sc]
    map<pair<int,int>,bool> mark;
    for (char c: s) {
        // cout << been[3][2] << endl;
        // mark current spot
        mark[{sr,sc}] = 1;
        // while the spot is marked, keep going
        // until you get to an unmarked spot
        while (mark[{sr,sc}]) {
            // cout << sr <<" "<<sc << endl;
            switch(c) {
                case 'N': sr--;break;
                case 'S': sr++;break;
                case 'E': sc++;break;
                case 'W': sc--;break;
            }
        }
    }
    cout << "Case #" << t << ": " << sr << " " << sc << endl;
}
}