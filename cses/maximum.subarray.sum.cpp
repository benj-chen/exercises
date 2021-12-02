#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nn(n);
    for (int i=0;i<n;i++) cin >> nn[n];
    for (int i=0;i<n-1;i+=2) {
        // merge positive
        if (nn[i]>-1 && nn[i+1]>-1) {
            nn[i]+=nn[i+1];
            nn.erase(nn.begin()+i+1);
        }
    }
    for (int i: nn) {
        cout << i << ' ';
    }
}