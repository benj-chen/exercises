#include <iostream>
using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    int score[n+1];
    for (int i=0;i<n;i++) cin >> score[i];
    score[n]=-1;
    int compare=score[k-1]-1>0 ? score[k-1]-1 : 0,total=0;
    for (int sc: score) {
        if (sc>compare) total++;
        else {
            cout << total << '\n';
            return 0;
        }
    }
}