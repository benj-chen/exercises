#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    q++;
    for (int w=1;w<q;w++) {
        cout << "Case #" << w << ": ";
        int e,a,b,c=0,j=0;
        cin >> e;
        vector<int> r[e];
        bool t[e];
        for (int i=0;i<e;i++){
            cin >> a >> b;
            r[i].push_back(a);
            r[i].push_back(b);
            r[i].push_back(i);
        }
        sort(r,r+e);
        for (vector<int> i: r) {
            if (i[0]>=c) {
                // c is ok
                c=i[1];
                t[i[2]]=1;
                continue;
            }
            if ( i[0]>=j ) {
                // j is ok
                j=i[1];
                t[i[2]]=0;
                continue;
            }
            cout << "IMPOSSIBLE";
            goto fin;
        }
        for (bool i: t) cout << (i? "C": "J");
        fin:;
        cout << '\n';
    }
}