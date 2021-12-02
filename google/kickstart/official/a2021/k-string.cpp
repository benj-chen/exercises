#include <bits/stdc++.h>

using namespace std;
// int main() {
//     int T;
//     cin >> T;
//     T++;
//     for (int t=1;t<T;t++) {
//         int N,n2, K,ct;
//         string s;
//         cin >> N >> K >> s;
//         ct=N%2;
//         cout << "Case #" << t << ": ";
//         n2=N/2;
//         string half1=s.substr(0,n2),half2="";
//         // reverse half2
//         for (int i=N-1;i>n2-!ct;i--) {
//             half2+=s[i];
//         }
//         ct=0;
//         for (int i=0;i<n2;i++) {
//             if (half1[i]!=half2[i]) ct++;
//         }
//         cout << half1 << " " << half2 << endl;
//         cout << ct << endl;
//         cout << (K<ct? 0: K-ct) << endl;
//     }
// }
int main() {
    int T;
    cin >> T;
    T++;
    for (int t=1;t<T;t++) {
        int N,n2, K,ct;
        string s;
        cin >> N >> K >> s;
        // 1 indexing f it
        s=" " + s;
        ct=0;
        cout << "Case #" << t << ": ";
        n2=N/2;
        for (int i=1;i<=n2;i++) {
            if (s[i]!=s[N-i+1]) ct++;
        }
        cout << (K>ct? K-ct : 0) << endl;
    }
}
// turns out you had to adjust down too... this problem
// would have been so easy if I knew how to read
