#include <bits/stdc++.h>
using namespace std;

int main() {
    using ar = array<int,3>;
    int k,m,n;
    cin>>k>>m>>n;
    vector<array<int,3>> pt(k);
    for (int i=0;i<k;i++) {
        cin>>pt[i][0] >> pt[i][1];
    }
    int f[m];
    for (int i=0;i<m;i++) {
        cin>>f[i];
    }
    long long res =0;
    // each of n can claim 2 spots, or more at the end and the beginning -- we want to claim the highest spots
    // group beginning and end together
    sort(f,f+m);
    sort(pt.begin(),pt.end());
    for (ar a: pt) {
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }
 
    int beg = f[0], nd = f[m-1], pt_s, pt_e;
    cout<<beg<<" "<<nd<<endl;
    for (int i=1;i<k;i++){
        if (i<=beg) {
            // clump previous with this
            pt[i][1] += pt[i-1][1];
        }
        else {
            // done clumping: remove all before i-1
            pt_s = i-1; // the true 0
            break;
        }
    }
    for (int i=k-2;i>0;i--) {
        if (i>=nd) {
            // clump after with this
            pt[i][1]+=pt[i+1][1];
        }
        else {
            pt_e = i+1;
            break;
        }
    }
    cout<<pt_s<<" " <<pt_e << endl;
    assert(pt_s<=pt_e);
    // get the maximum distance for each grass
    for (int i=pt_s+1;i<=pt_e;i++) {
        auto it = lower_bound(f,f+m,pt[i][0]);
        auto it2 = it-1;
        pt[i][2]=fmin(*it-pt[i][0], pt[i][0]-*it2);
    }
    
    for (ar a: pt) {
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }
    // always put a cow in between two spots inclusive

}