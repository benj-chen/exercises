#include <iostream>
#include <set>
using namespace std;
using us = set<int>;
int main() {
    int n,inp;
    cin >> n;
    us set;
    while (n--) {
        cin >> inp;
        set.insert(inp);
    }
    cout << set.size();
 
}