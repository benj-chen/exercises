
#include <iostream>
 
using namespace std;
int main() {
    int n,pass=0,maxpass=0,num_inp;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> num_inp;
        pass-=num_inp;
        cin >> num_inp;
        pass+=num_inp;
        if (pass > maxpass) maxpass=pass;
    }
    cout << maxpass << '\n';
}