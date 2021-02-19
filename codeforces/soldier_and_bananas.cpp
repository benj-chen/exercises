#include <iostream>
using namespace std;
int main() {
    int k,n,w;
    cin >> k >> n >> w;
    k= k * ((1+w)*w/2) - n; // reuse k to save memory
    cout << (k<0 ? 0 : k) << endl;
}