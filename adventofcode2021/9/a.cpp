#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> v;
    string s;
    int res=0;
    while (cin>>s) v.push_back(s);
    // normal
    for (int i=0;i<v.size();i++) for (int j=0;j<s.size();j++) {
        bool low=0;
        int k_st = -1, k_end = 2, l_st = -1, l_end = 2;

        if (!i) k_st = 0;
        else if (i==v.size()-1) k_end = 1;
        
        if (!j) l_st = 0;
        else if (j==s.size()-1) l_end = 1;
        
        for (int k=k_st;k<k_end;k++) for (int l=l_st;l<l_end;l++) if(k!=0 || l!=0) {
            if (v[i+k][j+l] <= v[i][j]) low=1;
        }
        if (!low) res+=v[i][j]-'0'+1;
    }
    cout<<res<<endl;
}