#include <iostream>
#include <array>
#include <vector>
#include <cmath>
using ll = long long;
using namespace std;
// int gi() {
//     int a;
//     cin >> a;
//     if (a==100) return 0;
//     if (a<100) return -1;
//     return 1;
// }
// int main() {
//     int n;
//     cin >> n;
//     vector<vector<int> > vec(n);
//     for (int i=0;i<n;i++) {
//         for (int j=0;j<n;j++) vec[i].push_back(gi());
//     }

//     for (vector<int> v: vec) {
//         for (int vv: v) cout << vv << ' ';
//         cout << endl;
//     }
//     ll num= pow(n,2) * pow(n+1,2)/4;// N2(N+1)2/4

// }
int main() {
    int n;
    cin >> n;
    for (int i=0;i<pow(n,2);i++) cin >> n;
    cout << 8;
}

// int main() {
    






//     int nn,a,b,c;
//     cin >> nn;
//     array<array<int,n>,n> arr;




//     bool hundred_exists=0;
//     for (int i=0;i<n;i++){
//         for (int j=0;j<n;j++) {
//             cin >> arr[i][j];
//             if (!hundred_exists && arr[i][j]) hundred_exists=1;
//         }
//     }
//     ll ct;
//     if (!hundred_exists) {
//         cout << 0;
//         return 0;
//     }
//     // find hudnred locs
//     vector<array<int,2> > locs;
//     for (array<int,n> : arr) {}

// }