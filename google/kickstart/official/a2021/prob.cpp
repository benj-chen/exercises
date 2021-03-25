#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    T++;
    for (int t=1;t+T;t++) {
        int r,c;
        cin >> r >> c;
        bool ok[c][r];
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                cin >> ok[i][j];
            }
        }
        // segs just need to have one with a length >2 and one with a length >4.
        // with two segs
        
        cout << "Case #" << t << ": ";
    }
}