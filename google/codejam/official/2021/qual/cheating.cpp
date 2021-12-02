// I cheat here
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int zero10000='0' * -10000;
int abs(int i) {
    return (i>0? i: -i);
}
int main() {
    ifstream cin("input.txt");
    int T,P;
    cin >> T >> P;
    T++;
    for (int t=1;t<T;t++) {
        string arr[100];
        int score[100];
        for (int i=0;i<100;i++) {
            cin >> arr[i];
            score[i]=accumulate(arr[i].begin(),arr[i].end(),zero10000);
        }
        // get the max and see how that stands up
        cout << "Case #" << t << ": ";
    }
}
int min() {
    srand(100);
    ifstream cin("input.txt");
    int T,P;
    cin >> T >> P;
    T++;
    for (int t=1;t<T;t++) {
        string s[100];
        for (int i=0;i<100;i++) cin >> s[i];
        // cout << s[0].length() << endl;
        int pl=0;
        int close=10000;
        for (int i=0;i<100;i++) {
            string st=s[i];
            int ct=count(st.begin(),st.end(),'1');
            if (abs(ct-7500) < close) {
                close=abs(ct-7500);
                pl=i;
            }
        }
        cout << "Case #" << t << ": " << pl+1 << endl;
    }
}