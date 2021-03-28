#include <bits/stdc++.h>
using namespace std;
int main() {
    int T,N,Q;
    cin >> T >> N >> Q;
    // think of this as a range of 1-N or 0-(N-1)
    // just pass test set 1 to win
    while (T--) {
        int medians[N-2];
        for (int i=0;i<N-2;i++) {
            cout << i+1 << i+2 << i+3 << endl;
            cin >> medians[i];
        }
        
    }
}