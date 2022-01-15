#include <bits/stdc++.h>
using namespace std;
int main() {
    char sign;
    int res=0;
    while (cin>>sign) {
        int i;
        cin >> i;
        if (sign=='+') {
            res+=i;
        }
        else res-=i;
    }
    cout<<res<<endl;
}