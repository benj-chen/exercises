#include <bits/stdc++.h>
using namespace std;
int main() { int T;cin>>T;T++;for(int t=1;t<T;t++) {
    cout << "Case #" << t << ": ";
    int n,m; cin >> n >> m;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    // take the m-1 biggest and sum; take median of (n-m+1) smallest numbers
    long long sum = 0;
    for (int i=0;i<m-1;i++) {
        sum+=a[n-i-1];
    }
    if ((n-m)%2) {
        long long res = (a[(n-m)/2] + a[(n-m)/2+1]);
        cout << sum + (res>>1);
        if (res%2) cout << ".5";
        cout << endl;
    }
    else {
        cout << sum + a[(n-m)/2] << endl;
    }
}
}