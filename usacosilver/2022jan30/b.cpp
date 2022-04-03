#include <bits/stdc++.h>
#define s second
#define f first
using namespace std;
using pii = pair<int,int>;
int main() {
    int n;
    cin >> n;
    vector<pii> ar(n);
    for (int i=0;i<n;i++) {
        cin >> ar[i].second;
        ar[i].first = i;
    }
    // if ar[i:j] is successful, then any indices betweeen i and j is unsuccessful if the other is before i or after j
    // abstract - base sz is 3 -> 2
    long long ct = 0;
    int prevsz = ar.size()+1;
    while (ar.size()!=prevsz) {
        prevsz = ar.size();
        for (int i=2;i<ar.size();i++) {
            if (ar[i].s > ar[i-1].s && ar[i-2].s > ar[i-1].s)
            {
                ct+=ar[i].f - ar[i-2].f + 1;
                ar.erase(ar.begin()+i-1);
                i++;
            }
        }
        
    }
    cout << ct + (n-1)*2 << endl;
}