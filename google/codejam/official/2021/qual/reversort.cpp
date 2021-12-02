#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    T++;
    for (int t=1;t<T;t++) {
        cout << "Case #" << t << ": ";
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i=0;i<n;i++) cin >> arr[i];
        int sum=0;
        // get the smallest value and spot
        while (!arr.empty()) {
            int smval_spot=0,smval=101;
            for (int i=0;i<arr.size();i++) {
                if (arr[i]<smval) {
                    smval=arr[i];
                    smval_spot=i;
                }
            }
            sum+=smval_spot+1;
            reverse(arr.begin(),arr.begin()+smval_spot+1);
            arr.erase(arr.begin());
            
        }
        cout << sum-1 << endl;
    }
}