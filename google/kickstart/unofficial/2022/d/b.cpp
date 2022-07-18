#include <bits/stdc++.h>
using namespace std;
int main() {
int T;cin>>T;T++;for(int t=1;t<T;t++) {
    int n,m,k; cin >> n;
    n++;
    vector<long long> a(n);
    a[0] = 0; // total sum is a[n-1]
    for (int i=1;i<n;i++) {
        cin >> k; // k is temporary here
        a[i] = a[i-1]+k;
    }
    cin >> m;
    m++;
    vector<long long> b(m);
    b[0]=0;
    for (int i=1;i<m;i++) {
        cin >> k; // k is temporary here
        b[i] = b[i-1]+k;
    }
    cin >> k;
    // 4 lines
    // fatal flaw in analysis: assumed that you would have to try 4 different ways to split K, but it's really 2
    // because you treat the forward and reverse lists the same
    // this takes the order from ~ K^4 (maybe K^3; both are too slow) to something more like K^2
    // will explain better, hopefully
    long long best_a[k+1] = {}, best_b[k+1]={}; // normalize to 0
    // build a
    for (int i=1;i<n;i++) for (int j=i /*inclusive*/; j<n;j++) {
        // amount of k used is n-j+i-2 (-1 for the fact that it's inclusive, -1 for the 0 in front)
        long long remove = a[j]-a[i-1];
        best_a[n-j+i-2] = fmax(best_a[n-j+i-2],a.back()-remove);
    }
    // build b
    for (int i=1;i<m;i++) for (int j=i /*inclusive*/; j<m;j++) {
        // amount of k used is m-j+i-2 (-1 for the fact that it's inclusive, -1 for the 0 in front)
        long long remove = b[j]-b[i-1];
        best_b[m-j+i-2] = fmax(best_b[m-j+i-2],b.back()-remove);
    }
    long long max = 0;
    for (int i=0;i<=k;i++) {
        max = fmax(max,best_a[i]+best_b[k-i]);
    }
    cout << "Case #" << t << ": " << max << endl;

}
}
/*
[0,1,2,3,4,5]
[0,1,3,6,10,15]
// sum from 2 to 4 or 2+3+4 = 9
10-1
// sum from 1 to 4 or 1+2+3+4=10

*/