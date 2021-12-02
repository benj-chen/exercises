#include <iostream>
#include <string>
using namespace std;
int main() {
    int x=0,n;
    cin >> n;
    string inp;
    for (int i=0;i<n;i++) {
        cin >> inp;
        inp[1]=='+' ? x++ : x--;
    }
    cout << x << '\n';
}