#include <bits/stdc++.h>
#define s second
#define f first
using namespace std;
using pii = pair<int,int>;
    vector<pii> ar(n);
int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> ar[i].second;
        ar[i].first = i;
    }
    // if ar[i:j] is successful, then any indices betweeen i and j is unsuccessful if the other is before i or after j
    // abstract - base sz is 3 -> 2
    for (int i=2;i<ar.size();i++) {
        if (ar[i-1].s < ar[i].s && ar[i-1].s < ar[i-2].s) {
            process(i-2,i,ar[i-1].s,ar[i-1].s);
        }
    }
}