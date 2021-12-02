#include <iostream>
#include <string>
using namespace std;
int main() {
    string stra,strb;
    cin >> stra >> strb;
    for (char &x: stra) x=tolower(x);
    for (char &x: strb) x=tolower(x);
    cout << (stra<strb ? -1 : stra==strb ? 0 : 1) << '\n';
}