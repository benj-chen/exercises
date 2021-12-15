#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool contains(string a, string b) {
    // if all letters in b are in a, return true
    for (char c: b) if (!binary_search(a.begin(),a.end(),c)) return 0;
    return 1;
}
long long sol = 0;
vector<string> input(10);
void solve() {
    vector<string> v(10);
    for (string& s: input) {
        sort(s.begin(),s.end()); // for contains and solving later
        switch(s.size()) {
            case 2: v[1]=s; break;
            case 3: v[7]=s; break;
            case 4: v[4]=s; break;
            case 7: v[8]=s; break;
        }
    }
    for (string s: input) if (s.size()==6) {
        if (!contains(s,v[1])) v[6]=s;
        else if (contains(s,v[4])) v[9]=s;
        else v[0]=s;
    }
    for (string s: input) if (s.size()==5) {
        if (contains(v[6],s)) v[5] = s;
        else if (contains(v[9],s)) v[3] = s;
        else v[2] = s;
    }
    int res = 0;
    for (int i=0;i<4;i++) {
        res*=10;
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        for (int i=0;i<10;i++) {
            if (s==v[i]) {
                res+=i;
            }
        }
    }
    sol += res;
}

int main() {
    while (cin>>input[0]) {
        for(int i=1;i<10;i++) {
            cin>>input[i];
        }
        cin.ignore(2); // |
        solve();
    }
    cout<<sol<<endl;
}