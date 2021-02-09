#include <iostream>
using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    int score[n+1];
    for (int i=0;i<n;i++) cin >> score[i];
    score[n]=-1; // guarantee that else statement
    int compare=score[k-1]-1>0 ? score[k-1]-1 : 0 // if the compare is -1 (really 0), make it 0.
    ,total=0;
    for (int sc: score) {
        if (sc>compare) total++;
        else {
            cout << total << '\n';
            return 0;
        }
    }
}