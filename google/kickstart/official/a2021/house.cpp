#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    T++;
    for (int t=1;t<T;++t) {

        int R,C;
        cin >> R >> C;
        cout << "Case #" << t << ": ";
        int ht[C][R];
        for (int i=0;i<R;i++) {
            for (int j=0;j<C;j++) cin >> ht[i][j];
        }
        // build an array of sets about the number(s) that it must be. Then each one
        // may be combined..? idk. The numbers must be greater than what's already there
        
        set<int> could_be[C][R];
        // corners and edges
        for (int i=0;i<R;i+=R-1) {
            for (int j=0;j<C;j+=C-1){
                
            }
        }
        for (int i=1;i<R-1;i++) {
            for (int j=1;j<C-1;j++) {
                // center
            }
        }
    }
}