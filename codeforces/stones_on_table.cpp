#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int ct;
    string s;
    cin >> ct >> s;
    /*
    vector<string> groups={"0"}; // prevent seg fault
    
    for (char x: s) {
        if ((groups.back()[0])==x) groups.back()+=x;
        else groups.push_back(string(1,x));
    }
    cout << ct-(groups.size()-1) << '\n'; // size-1 is how many are left at the end
    */
    string cur_group=".";
    for (char x : s) {
        if (cur_group[0]==x) cur_group=string(1,x);
        else ct--;
    }
    cout << ct << '\n';
}