#include <iostream>
#include <string>
using namespace std;

int main() {
    string s,visited;
    cin >> s;
    bool bg =0,newchar;// boy girl
    for (char &x: s) {
        newchar=1;
        for (char &y: visited) {
            if (x==y) {
                newchar=0;
                break;
            }
        }
        if (newchar) {
            visited+=x;
        }
    }
    cout << (bg ? "IGNORE HIM!" : "CHAT WITH HER!") << '\n';
}