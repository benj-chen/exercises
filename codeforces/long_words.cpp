#include <iostream>
#include <string>
using namespace std;
int main() {
    int n,len;
    cin >> n;
    string s;
    for (int i=0;i<n;i++) {
        cin >> s;
        len = s.length();
        if (len < 11) {
            cout << s << '\n';
            continue;
        }
        cout << s[0] << len-2 << s[len-1] << '\n';
    }
}
