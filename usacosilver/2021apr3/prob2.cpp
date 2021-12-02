#include <bits/stdc++.h>

using namespace std;
int n;
int main() {
    /*
    assume that the maximum that a can be is the minimum of the whole thing,
    and the minimum that a+b+c can be is the maximum of the whole thing.
    1≤a≤b≤c
    adding them all together would be a+b+c+a+b+b+c+c+a+a+b+c
    or 4a+4b+4c -whatever's missing
    note that this number could exceed int range, use long
    The terms in order:
    a
    b
    (c, a+b)
    c+a
    c+b
    a+b+c
    */
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int i=0;i<n;i++) cin >> arr[i];
        sort(arr,arr+n);
        if (n==7) {
            cout << 1 << endl;

        }
    }
}