#include <iostream>
using namespace std;
int main() {
    int n,k,i;
    cin >> n >> k;
    for (i=0;i<k;i++) (n/10*10==n ? n/=10:n--);
    cout << n << endl;
}