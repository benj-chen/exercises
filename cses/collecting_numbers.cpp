#include <iostream>
using namespace std;
int main() {
    int n,raw_input;
    cin >> n;
    int s[n];
    for (int i=0;i<n;i++) {
        cin >> raw_input;
        s[raw_input-1]=i;
    }
    raw_input=1; // now serves as count
    n--;
    while (n--) if (s[n]>s[n+1]) raw_input++;
    cout << raw_input << endl;
}