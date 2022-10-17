
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// bool less(array<ll,3> a, array<ll,3> b) {
//     return a[0] < b[0];
// }
pair<int,int> max(vector<pair<int,int>>& v) {
    int res = 0;
    int quan = -1;
    for (auto i: v) {
        res = fmax(res,i.first);
        if (i.first>res) {
            res=i.first;
            quan=i.second;
        }
    }
    return {res,quan};
}
int main(){
int T;cin>>T;T++;for(int t=1;t<T;t++) {
    long long final_value = 0;
    int d,n,x; cin >> d >> n >> x;
    vector<array<int,3>> seeds;
    for (int i=0;i<n;i++) {
        int q,l,v;
        cin >> q >> l >> v;
        // priority: l
        seeds.push_back({l,v,q});
    }
    // sort(seeds.begin(),seeds.end(),less);
    // separate schedule by expiration (shortest first)
    // capacity per arc is length (exp[b] - exp[a]) * x
    // extras can replace earlier stuff
    // watch for same expiration
    vector<int> exp = {0,d};
    for (auto i: seeds) exp.push_back(i[0]);
    sort(exp.begin(),exp.end());
    map<int,vector<pair<int,int>> > pools; // val, quan
    for (int i=0;i<n;i++) {
        pools[seeds[i][0]].push_back({seeds[i][1],seeds[i][2]});
    }
    // for (pair<int,vector<pair<int,int>>> p: pools) {
        // cout << p.first << " ";
        // for (pair<int,int> q: p.second) {
            // cout <<"("<<q.first<<","<<q.second<<")"<<endl;
        // }
    // }
    priority_queue<int> extra; //val
    map<int,int> extra_quan; // val, quantity
    // special first set
    // capacity = x
    for (int i=0;i<exp.size()-2;i++) {
        // cout << "i" << exp[i] << endl;
        // pools[i] is the newest batch
        // take exp[i]-exp[i-1] * x best seeds among the extra and this
        // add to extra
        if (exp[i+1]-exp[i] ==0) continue;
        // cout << pools[exp[i]].size() << endl;
        for (auto j: pools[exp[i+1]]) {
            // cout << j.first << "," << j.second << endl;
            extra.push(j.first);
            extra_quan[j.first]+= j.second;
        }
        int capacity = (exp[i+1]-exp[i]) * x;
        if (i==0) capacity = x;
            // cout << capacity  << "c" << endl;
        while (capacity >0) {
            // keep pulling from top
            if (extra.empty()) break;
            int val = extra.top();
            // cout << "val"<<val << endl;
            // extra.pop();
            // cout << "test " << extra.top() << endl;break;
            int quan = extra_quan[val];
            if (quan>capacity) {
                final_value += capacity * val;
                // cout << "capacity " << capacity << " val " << val << endl;
                extra_quan[val] -= capacity;
            }
            else {
                final_value += quan * val;
                // cout << "quan " << quan << " val " << val << endl;
                extra_quan[val] = 0;
                extra.pop();
            }
            capacity -= quan;
            // cout << capacity  << "c" << endl;
        }
    }
    cout << "Case #" << t << ": " <<final_value << endl;
}
}