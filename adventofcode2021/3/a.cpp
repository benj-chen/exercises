#include <iostream>
#include <vector>
using namespace std;
int main() {
    string s;
    vector<string> v;
    while (cin>>s) {
        v.push_back(s);
    }
    int common[s.size()] = {}; // init all to 0
    for (string st: v) {
        for (int i=0;i<s.size();i++) {
            if (st[i]=='0') common[i]--;
            else common[i]++;
        }
    }
    int gamma = 0, epsilon=0;
    for (int i: common) {
        gamma<<=1;
        epsilon<<=1;
        if (i>0)
            gamma++;
        else epsilon++;
    }
    cout<<gamma*epsilon<<endl;
}