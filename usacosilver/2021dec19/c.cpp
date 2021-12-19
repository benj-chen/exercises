#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    int a[n], b[n];
    long long ud[2*m+1];
    for (int i=0;i<n;i++) cin >> a[i] >> b[i];
    for (int i=0;i<n;i++) {
        ud[a[i]*2]++; // avoid double counting
        ud[b[i]*2+1]--;
        for (int j=i+1;j<n;j++) {
            ud[a[i]+a[j]]+=2;
            ud[b[i]+b[j]+1]-=2;
        }
    }
    long long num=0;
    for (long long i: ud) {
        num+=i;
        cout<<num<<endl;
    }
}