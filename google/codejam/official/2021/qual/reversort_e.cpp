#include <bits/stdc++.h>
using namespace std;
vector<string> ans(const vector<string>& l) {
    if (l.size()==1) return l;
    vector<string> res;
    vector<string> c=l;
    sort(c.begin(),c.end());
    for (string x: l) {
        for (int i=0;i<c.size();i++) {
            if(c[i]==x) {
                c.erase(c.begin()+i);
                break;
            }
        }
        vector<string> t = ans(c);
        for (string y: t) {
            res.push_back(x+y);
        }
        c=l;
        sort(c.begin(),c.end());
    }
    return res;
}
int reversort(vector<int> arr) {
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
    return sum-1;
}
int main() {
    int T;
    // ifstream cin("input.txt");
    cin >> T;
    T++;
    for (int t=1;t<T;t++) {
        int n,c;
        cin >> n >> c;
        vector<string> st;
        for (int i=0;i<n;i++) {
            st.push_back(to_string(i+1));
        }
        cout << "Case #" << t << ": ";
        for (string s: ans(st)) { // use as set if needed, or every 6
            vector<int> go;
            for (int i=0;i<n;i++) {
                go.push_back(stoi(s.substr(i,1)));
            }
            if (reversort(go)==c) {
                for (int i=0;i<go.size()-1;i++) {
                    cout << go[i] << " ";
                }
                cout << go.back() << endl;
                goto done;
            }
        }
        // permute
        cout << "IMPOSSIBLE\n";
        done:;
        
    }
}