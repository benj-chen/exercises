#include <bits/stdc++.h>
using namespace std;
string vstr(vector<bool>& v) {
    string s="";
    for (int i: v) s+=i;
    return s;
}
int main() {
    int n; cin >> n;
    // recursion, abba
    // vector<int> v = {1,2,3,4,5};
    // sort(v.begin(),v.end(),less<int>()); // algorithm and functional
    // for (int i: v) {
    //     cout << i << endl;
    // }
    vector<bool> digits(n);
    // done when the formula reaches (n-1)**2
    n--;
    string digit_str="";
    for (int i=0;i<n;i++) digit_str+="0";
    string done=to_string(pow(2,n-1));
    
    cout << digit_str;
}