#include <iostream>
#include <string>
#define vowels "AEIOUYaeiouy"
using namespace std;
string goalstr(char &elem) {
    for (char x: vowels) {
        if (x==elem) return "";
    }
    return "."+string(1,tolower(elem)); // had to use google for that one
}
int main() {
    string s;
    cin >> s;
    string res;
    for (char &x: s) res+=goalstr(x);
    cout << res << '\n';
}