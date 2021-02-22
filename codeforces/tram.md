for some reason this didn't work with the online compiler:

#include <iostream>

using namespace std;
int inp;
int geti() {
    cin >> inp;
    return inp;
}
int main() {
    int n,pass=0,maxpass=0;
    cin >> n;
    for (int i=0;i<n;i++) {
        pass+=-geti()+geti();
        if (pass > maxpass) {
            maxpass=pass;
        }
    }
    cout << maxpass << '\n';
}

