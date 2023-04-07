
#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<deque>
#include<cmath>
#define fr(i,m,n) for (int i=m;i<n;i++)
#define fo(i,n) fr(i,0,n)
#define f(n) fo(i,n)
using namespace std;
string get_increasing(vector<int> a) {
    // for (int i: a) cout << i << endl;
    deque<string> res;
    // back is 0
    f(a.size()) {
    // int i = 0;
        // dance q/2 times
        int mult = a[i]/2; // L... R...
        // extend until the next is less than first
        int ext =1;
        int min = a[i];
        fr(j,i+1,a.size()) {
            if (a[j] < a[i]) break;
            a[j] -= a[i];
            ext++;
        }
        // cout << "ext " << ext << endl;
        fo(j,mult) {
            res.push_back(string(ext,'L'));
            res.push_back(string(ext,'R'));
        }
    }
    string fin;
        for (string i: res) fin+=i;
        return fin;
}
string flip(string s) {
    for (char& c: s) {
        if (c=='L') c='R';
        else c= 'L';
    }
    return s;
    for (int i=0;i<s.size()/2;i++) {
        char c = s[i];
        s[i] = s[s.size()-1-i];
        s[s.size()-1-i] = c;
    }
    return s;
}
int n;
int main() {
    cin >> n;
    vector<int> a(n);
    f(n) cin >> a[n-1-i];
    f(n) a[i]-=2;
    // for (int i: a) cout << i << endl;
    deque<string> res;
    // back is 0

    f(n) {
        // non decreasing
        if (a[i] < a[i+1]) {
            
        vector<int> vi;
        for (int j=i;a[j] >= a[i];j++) { 
            vi.push_back(a[j]);
        }
        // add this
        res.push_back(get_increasing(vi));
        res.push_front("L");
        res.push_back("R");
        i += vi.size();
        }
        else {
        vector<int> vi;
        for (int j=i;a[j] <= a[i];j++) { 
            vi.push_back(a[j]);
        }
        // add this
        res.push_back(flip(get_increasing(vi)));
        res.push_front("L");
        res.push_back("R");
        i += vi.size();
        }
    }
    // f(n) {
    //     top:;
    // // int i = 0;
    //     // dance q/2 times
    //     // extend until the next is less than first
    //     int ext =1;


    //     int min = a[i];
    //     if (min == 0) continue;
    //     fr(j,i+1,n) {
    //         if (a[j] < a[i] and a[j] > 0) {
    //             min = fmin(min,a[j]);
    //             ext++;
    //         }
    //         else break;
    //     }
    //     fo(j,ext) {
    //         a[j+i] -= min;
    //     }
    //     int mult = min/2;

    //     // cout << "ext " << ext << endl;
    //     fo(j,mult) {
    //         res.push_back(string(ext,'L'));
    //         res.push_back(string(ext,'R'));
    //     }
    //     goto top;
    // }
        for (string i: res) cout << i;
        cout << endl;

}