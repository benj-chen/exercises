#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    cin >> a;
    a++;
    for (int i=1;i<a;i++) {
        cout << "Case #" << i << ": ";
        int n,k;
        cin >> n >> k;
        // each number appears n times
        if (k>n*n || k<n) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        cout << "POSSIBLE\n";
        int sq[n][n];
        
        for (int i=0;i<n;i++) {
            sq[i][i]=1;
        }
        k-=n;
        for (int i=0;i<n;i++) {
            if (!k) break;
            if (k>=n) {
                sq[i][i]=n;
                k-=n-1;
            }
            else {
                sq[i][i]=k+1;
                break;
            }
        } // this could be more efficient, worry later

        // fill up
        // give each possible numbers, start with the least options and work from there
        vector<set<int> >couldntBe[n];
        for (vector<set<int> > vec: couldntBe) vec.resize(n);
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (i-j) { // if i and j are different
                    // each spot that isn't along the diag has 2 can't-be's to start
                    couldntBe[i][j].insert(sq[i][i]);
                    couldntBe[i][j].insert(sq[j][j]);
                }
            }
        }
        
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cout << sq[i][j] << ' ';
            }
            cout << endl;
        }
        
    }
    
    
}