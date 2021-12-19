#include <bits/stdc++.h>
using namespace std;
int main() {
int t;
cin>>t;
for (int T=0;T<t;T++) {
    int n,m;
    cin>>n>>m;
    if (m==0) {
        cout << (n-1) * (n-1) << endl;
        break;
    }
    // highest point connected to 1
    vector<int> connto1 = {1};
    vector<int> connton = {n};
    vector<pair<int,int>> nums;
    for (int i=0;i<m;i++) {
        int a,b; cin >> a >> b;
        nums.push_back(make_pair(fmin(a,b),fmax(a,b)));
    }
    sort(nums.begin(),nums.end());
    for (pair<int,int> i: nums) cout << i.first<<" " <<i.second<<endl;
    int numconn = 2;
    int res = 0;
    if (nums[0].first!=1) {
        // make conn to 1 necessary
        numconn--;
        res+=(nums[0].first-1) * (nums[0].first-1);
    }
    if (nums.back().second!=n) {
        numconn--;
        res+=(n-nums.back().second) * (n-nums.back().second);
    }
    if (numconn==0) goto end;
    if (numconn==1) {
        // 1 connection; find and solve
    }
    end:;
    /*
    for (pair<int,int> p: nums) {
        // revisit this
        for (int x: connto1) {
            if (x==p.first) {
                connto1.push_back(p.second);
            }
            else if (x==p.second) {
                connto1.push_back(p.first);
            }
        }
        for (int x: connton) {
            if (x==p.first) connton.push_back(p.second);
            else if (x==p.second) connton.push_back(p.first);
        }
    }
    int highest = 1;
    for (int i: connto1) {
        if (i>highest) highest=i;
    }
    int lowest = n;
    for (int i: connton) {
        if (i<lowest) lowest=i;
    }
    int a = (lowest-highest)/2;
    int b = lowest-a-highest;
    cout<< a*a + b*b << endl;
    */
}
}